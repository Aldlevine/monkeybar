#ifndef MONKEYBAR_COMPONENT_H
#define MONKEYBAR_COMPONENT_H

#include "trie.h"

typedef struct Component {
  char        *type;
  char        *name;
  TrieNode *properties; /* Should hide trie implementation */
} Component;

#endif /* MONKEYBAR_COMPONENT_H */
