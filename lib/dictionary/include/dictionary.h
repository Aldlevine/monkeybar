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
#include <stdarg.h>

#include "trie/trie.h"

typedef struct dictionary_s {
  TrieNode *_data; /* trie implementation hidden here */
} Dictionary;

/**
 * @brief creates a `dictionary`
 *
 * @param   ...  a list of pairs of `key`, `value`, terminated with NULL
 * @return       the newly created dictionary
 *
 * @code
 * // Create empty dictionary
 * dictionary_create(NULL);
 *
 * // Create dictionary with values
 * dictionary_create(
 *   "key1", "value",
 *   "key2", some_pointer,
 *   "key3", false,
 *   NULL);
 * @endcode
 */
Dictionary *dictionary_create (char *first, ...);

/**
 * @brief frees a dictionary from memory
 *
 * @param dictionary the `dictionary` to free
 */
void dictionary_free (Dictionary *dictionary);

/**
 * @brief sets a `key` to a `value` for a given `dictionary`
 *
 * @param dictionary the `dictionary` to set the `key`
 * @param key the `key` to set
 * @param `value` the `value` to set `key` to
 * @return `true` if succcessful, `false` otherwise
 */
bool dictionary_set (Dictionary *dictionary, char *key, void *value);

/**
 * @brief gets the value of `key` in a `dictionary`
 *
 * @param dictionary the `dictionary` to get the value from
 * @param key the `key` where the desired value is
 * @return the value at `key` or `NULL` of it doesn't exist
 */
void* dictionary_get (Dictionary *dictionary, char *key);

/**
 * @brief deletes `key` from `dictionary`
 *
 * @param dictionary the `dictionary` to delete the key from
 * @param key the `key` to delete
 * @return `true` if successful, `false` otherwise
 */
bool dictionary_delete (Dictionary *Dictionary, char *key);

#endif /* MONKEYBAR_DICTIONARY_H */
