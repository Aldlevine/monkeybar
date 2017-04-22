#ifndef MONKEYBAR_VECTOR_S_H
#define MONKEYBAR_VECTOR_S_H

#include <stdlib.h>
#include "vector_node_s.h"

typedef struct _Vector_s {
  size_t     length;
  VectorNode *head;
  VectorNode *tail;
} Vector;

#endif /* MONKEYBAR_VECTOR_S_H */
