#include "trie.h"

typedef struct event_target_s {
  char *type;
  trie_node_t *properties;
} event_target_t;

