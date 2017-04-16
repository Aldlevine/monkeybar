/**
 * @file dictionary.h
 * A simple wrapper module that creates a dictionary object.
 *
 * The design is intended to abstract the dictionary interface
 * from the backing algorithm. Currently, a trie is used as the
 * backing algorithm, but with this abstraction, it could be
 * replaced with any backing algorithm in the future and prevent
 * large changes from propagating through all depentent modules
 */

#ifndef MONKEYBAR_DICTIONARY_H
#define MONKEYBAR_DICTIONARY_H

#include <stdbool.h>

#include "trie.h"

typedef struct dictionary_s {
  trie_node_t *_data; /* trie implementation hidden here */
} dictionary_t;

/**
 * @brief creates a `dictionary`
 *
 * @return the newly created dictionary
 */
dictionary_t *dictionary_create ();

/**
 * @brief frees a dictionary from memory
 *
 * @param dictionary the `dictionary` to free
 */
void dictionary_free (dictionary_t *dictionary);

/**
 * @brief sets a `key` to a `value` for a given `dictionary`
 *
 * @param dictionary the `dictionary` to set the `key`
 * @param key the `key` to set
 * @param `value` the `value` to set `key` to
 * @return `true` if succcessful, `false` otherwise
 */
bool dictionary_set (dictionary_t *dictionary, char *key, void *value);

/**
 * @brief gets the value of `key` in a `dictionary`
 *
 * @param dictionary the `dictionary` to get the value from
 * @param key the `key` where the desired value is
 * @return the value at `key` or `NULL` of it doesn't exist
 */
void* dictionary_get (dictionary_t *dictionary, char *key);

/**
 * @brief deletes `key` from `dictionary`
 *
 * @param dictionary the `dictionary` to delete the key from
 * @param key the `key` to delete
 * @return `true` if successful, `false` otherwise
 */
bool dictionary_delete (dictionary_t *dictionary_t, char *key);

#endif /* MONKEYBAR_DICTIONARY_H */
