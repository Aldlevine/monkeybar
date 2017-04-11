#include "trie.h"

typedef struct component_s {
  char        *type;
  char        *name;
  trie_node_t *properties;
} component_t;
