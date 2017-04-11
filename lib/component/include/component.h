#ifndef MONKEYBAR_COMPONENT_H
#define MONKEYBAR_COMPONENT_H

#include "trie.h"

typedef struct component_s {
  char        *type;
  char        *name;
  trie_node_t *properties; /* Should hide trie implementation */
} component_t;

#endif /* MONKEYBAR_COMPONENT_H */
