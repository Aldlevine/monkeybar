#include "vector.h"

typedef struct VectorNode_s {
  void                *data;
  struct VectorNode_s *next;
  struct VectorNode_s *prev;
} VectorNode;
