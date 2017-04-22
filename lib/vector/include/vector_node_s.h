#ifndef MONKEYBAR_VECTOR_NODE_S_H
#define MONKEYBAR_VECTOR_NODE_S_H

#include "vector_node_s.h"

typedef struct _VectorNode_s {
  void                 *data;
  struct _VectorNode_s *prev;
  struct _VectorNode_s *next;
} VectorNode;

#endif /* MONKEYBAR_VECTOR_NODE_S_H */
