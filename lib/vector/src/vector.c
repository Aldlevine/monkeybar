#include "vector.h"
#include "vector_s.h"
#include "vector_node_s.h"

typedef struct _VectorNode_s VectorNode;


/**
 * creates a VectorNode
 *
 * @param   data  the data the node represents
 * @param   prev  the previous VectorNode
 * @param   next  the next VectorNode
 * @return        the newly created VectorNode
 */
VectorNode*
vector_node_create (void *data, VectorNode *prev, VectorNode *next)
{
  VectorNode *node = malloc(sizeof(VectorNode));
  node->data = data;
  node->prev = prev;
  node->next = next;
  return node;
}

/**
 * frees a VectorNode
 *
 * @param   node  the node to free
 */
void
vector_node_free (VectorNode *node)
{
  free(node);
}

Vector*
vector_create (size_t count, ...)
{
  Vector *vector = malloc(sizeof(Vector));
  vector->length = count;

  VectorNode *prev, *node;

  va_list ap;
  va_start(ap, count);
  /* {{{ */

    node = prev = vector_node_create(va_arg(ap, void *), NULL, NULL);
    vector->head = prev;

    for (size_t i=1; i<count; i++)
    {
      node = vector_node_create(va_arg(ap, void *), prev, NULL);
      prev->next = node;
      prev = node;
    }

  /* }}} */
  va_end(ap);

  vector->tail = node;

  return vector;
}

void
vector_free (Vector *vector)
{
  VectorNode *next, *node = vector->head;

  size_t i = vector->length;

  if (i==0)
  {
    return;
  }

  while (--i>0)
  {
    next = node->next;
    vector_node_free(node);
    node = next;
  }

  free(vector);
}

size_t
vector_length (Vector *vector)
{
  return vector->length;
}

VectorNode*
_vector_get (Vector *vector, size_t index)
{
  size_t i, length = vector->length;
  VectorNode *node;

  /* closer to tail */
  if (index > length - index)
  {
    i = 0;
    size_t offset = length - index - 1;
    node = vector->tail;
    while (i++<offset)
    {
      node = node->prev;
    }
  }
  /* closer to head */
  else
  {
    i = 0;
    node = vector->head;
    while (i++<index)
    {
      node = node->next;
    }
  }
  return node;
}

void*
vector_get (Vector *vector, size_t index)
{
  return _vector_get(vector, index)->data;
}

size_t
vector_push (Vector *vector, void *data)
{
  if (vector->length == 0)
  {
    vector->head = vector->tail = vector_node_create(data, NULL, NULL);
    vector->length = 1;
    return 0;
  }
  VectorNode *node = vector_node_create(data, vector->tail, NULL);
  vector->tail->next = node;
  vector->tail = node;
  return vector->length++;
}

void*
vector_pop (Vector *vector)
{
  VectorNode *node;
  void *data;
  switch (vector->length)
  {
    case 0:
      return NULL;
    case 1:
      node = vector->tail;
      data = node->data;
      vector->head = NULL;
      vector->tail = NULL;
      vector_node_free(node);
      vector->length = 0;
      return data;
    default:
      node = vector->tail;
      data = node->data;
      vector->tail = node->prev;
      vector->tail->next = NULL;
      vector_node_free(node);
      vector->length--;
      return data;
  }
}

size_t
vector_unshift (Vector *vector, void *data)
{
  if (vector->length == 0)
  {
    vector->head = vector->tail = vector_node_create(data, NULL, NULL);
    vector->length = 1;
    return 1;
  }
  VectorNode *node = vector_node_create(data, NULL, vector->head);
  vector->head->prev = node;
  vector->head = node;
  return ++vector->length;
}

void*
vector_shift (Vector *vector)
{
  VectorNode *node;
  void *data;
  switch (vector->length)
  {
    case 0:
      return NULL;
    case 1:
      node = vector->tail;
      data = node->data;
      vector->head = NULL;
      vector->tail = NULL;
      vector_node_free(node);
      vector->length = 0;
      return data;
    default:
      node = vector->head;
      data = node->data;
      vector->head = node->next;
      vector->head->prev = NULL;
      vector_node_free(node);
      vector->length--;
      return data;
  }
}

size_t
vector_insert (Vector *vector, size_t index, size_t count, ...)
{
  if (count == 0)
  {
    return vector->length;
  }

  VectorNode *node, *prev, *next;

  va_list ap;
  va_start(ap, count);
  /* {{{ */

    if (index == 0)
    {
      prev = vector_node_create(va_arg(ap, void*), NULL, NULL);
      vector_unshift(vector, prev);
      count--;
    }
    else
    {
      prev = _vector_get(vector, index - 1);
    }
    next = prev->next;

    for (size_t i=0; i<count; i++)
    {
      node = vector_node_create(va_arg(ap, void *), prev, NULL);
      prev->next = node;
      prev = node;
    }

    node->next = next;
    next->prev = node;

  /* }}} */
  va_end(ap);

  return vector->length += count;
}

Vector*
vector_extract (Vector *vector, size_t index, size_t count)
{

  VectorNode *before;
  VectorNode *start;
  if (index == 0)
  {
    before = NULL;
    start = vector->head;
  }
  else
  {
    before = _vector_get(vector, index - 1);
    start = before->next;
  }
  VectorNode *after = start;
  VectorNode *end;

  for (size_t i=count; i>0; i--)
  {
    end = after;
    after = after->next;
  }


  if (index != 0)
  {
    before->next = after;
  }
  after->prev = end;

  Vector *result = vector_create(0);
  result->head = start;
  result->tail = end;
  result->length = count;

  vector->length -= count;

  return result;
}

void
vector_each (Vector *vector, void (*fn)(size_t, void*, Vector*))
{
  size_t i, length = vector->length;
  VectorNode *node = vector->head;
  for (i=0; i<length; i++)
  {
    (*fn)(i, node->data, vector);
    node = node->next;
  }
}
