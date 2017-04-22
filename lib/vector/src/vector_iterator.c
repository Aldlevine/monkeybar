#include "vector_node_s.h"
#include "vector_s.h"
#include "vector_iterator.h"

struct _VectorIterator_s {
  Vector     *vector;
  VectorNode *node;
};

VectorIterator *
vector_iterator_create (Vector *vector)
{
  VectorIterator *vector_iterator = malloc(sizeof(VectorIterator));
  vector_iterator->vector         = vector;
  vector_iterator->node           = vector->head;
  return vector_iterator;
}

void
vector_iterator_free (VectorIterator *vector_iterator)
{
  free(vector_iterator);
}

bool
vector_iterator_next (VectorIterator *vector_iterator, void **data)
{
  if (vector_iterator->node == NULL)
  {
    return false;
  }
  *data = vector_iterator->node->data;
  vector_iterator->node = vector_iterator->node->next;
  return true;
}
