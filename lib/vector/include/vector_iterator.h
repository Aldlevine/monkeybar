#ifndef MONKEYBAR_VECTOR_ITERATOR_H
#define MONKEYBAR_VECTOR_ITERATOR_H

#include <stdbool.h>
#include "vector.h"

typedef struct _VectorIterator_s VectorIterator;

VectorIterator * vector_iterator_create (Vector *vector);

void vector_iterator_free (VectorIterator *vector_iterator);

bool vector_iterator_next (VectorIterator *vector_iterator, void **data);


#define VECTOR_EACH(v, d)                             \
  do {                                                \
    void *d;                                          \
    VectorIterator *_vi_ = vector_iterator_create(v); \
    while (vector_iterator_next(_vi_, &d))

#define END_VECTOR_EACH \
    free(_vi_);          \
  } while (0)

#endif /* MONKEYBAR_VECTOR_ITERATOR_H */
