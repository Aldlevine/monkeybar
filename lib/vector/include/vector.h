#ifndef MONKEYBAR_VECTOR_H
#define MONKEYBAR_VECTOR_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct VectorNode_s VectorNode;

typedef struct Vector_s {
  size_t     length;
  VectorNode *head;
  VectorNode *tail;
} Vector;

/**
 * creates a vector
 *
 * @param   count  the number of elements to initialize the vector to
 * @param   ...    the elements to initialize the element with
 * @return         the newly created vector
 */
Vector* vector_create  (size_t count, ...);

/**
 * frees a vector
 *
 * @param  vector  the vector to free
 */
void vector_free       (Vector *vector);

/**
 * gets an element from a vector
 *
 * @param   vector  the vector to get the element from
 * @param   index   the indec where the element is
 * @return          the element at index
 */
void* vector_get       (Vector *vector, size_t index);

/**
 * pushes an element onto the tail of a vector
 *
 * @param   vector   the vector to add the element to
 * @param   element  the element to add to the vector
 * @return           the index of the added element
 */
size_t vector_push     (Vector *vector, void *element);

/**
 * pops an element from the end of a vector
 *
 * @param   vector  the vector to pop an element from
 * @return          the element at the tail of the vector
 */
void* vector_pop       (Vector *vector);

/**
 * unshifts an element onto the head of a vector
 *
 * @param   vector   the vector to add the element to
 * @param   element  the element to add
 * @return           the new size of the vector
 */
size_t vector_unshift  (Vector *vector, void *element);

/**
 * shifts an element from the head of a vector
 *
 * @param   vector  the vector to shift an element from
 * @return          the element at the head of the vector
 */
void* vector_shift     (Vector *vector);

/**
 * inserts a number of elements to a vector at index
 *
 * @param   vector  the vector to insert into
 * @param   index   the index to start insertion at
 * @param   count   the number of elements to insert
 * @param   ...     the elements to insert
 * @return          the new size of the vector
 */
size_t vector_insert   (Vector *vector, size_t index, size_t count, ...);

/**
 * extracts a number of elements from a vector
 *
 * @param   vector  the vector to extract from
 * @param   index   the index to start extraction at
 * @param   count   the number of elements to extract
 * @return          a new Vector with the extracted elements
 */
Vector* vector_extract (Vector *vector, size_t index, size_t count);

/**
 * iterates over all elements and calls `fn` with their index and data
 *
 * @param   vector  the vector to iterate over
 * @param   fn      the callback function that will be called for each element
 */
void vector_each       (Vector *vector, void (*fn)(size_t, void*, Vector*));

#endif /* MONKEYBAR_VECTOR_H */
