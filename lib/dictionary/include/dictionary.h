#ifndef MONKEYBAR_DICTIONARY_H
#define MONKEYBAR_DICTIONARY_H

#include "trie.h"

typedef struct dictionary_s {
  trie_node_t *data; /* trie implementation hidden here */
} dictionary_t;

#endif /* MONKEYBAR_DICTIONARY_H */
