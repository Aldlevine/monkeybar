#ifndef MONKEYBAR_DICTIONARY_H
#define MONKEYBAR_DICTIONARY_H

#include <stdbool.h>

#include "trie.h"

typedef struct dictionary_s {
  trie_node_t *_data; /* trie implementation hidden here */
} dictionary_t;

dictionary_t *dictionary_create ();

void dictionary_free (dictionary_t *dictionary);

bool dictionary_set (dictionary_t *dictionary, char *key, void *value);

void* dictionary_get (dictionary_t *dictionary, char *key);

bool dictionary_delete (dictionary_t *dictionary_t, char *key);

#endif /* MONKEYBAR_DICTIONARY_H */
