/**
 * @file trie.h
 */

#ifndef  MONKEYBAR_TRIE_H
#define  MONKEYBAR_TRIE_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct trie_node_s trie_node_t;

/**
 * @brief creates a `trie_node_t` to use as a root node
 *
 * @return a `trie_node_t` root node
 */
trie_node_t *trie_create (void);

/**
 * @brief frees a `trie_node_t` and all of its children
 *
 * @param node the trie to free
 */
void trie_free (trie_node_t *node);

/**
 * @brief sets `key` to `value`
 *
 * @param root the `trie_node` to insert into
 * @param key the key to set
 * @param value the value to set `key` to
 * @return `true` if successful, `false` otherwise
 */
bool  trie_set (trie_node_t *root, char *key, void *value);

/**
 * @brief gets `value` at `key`
 *
 * @param root the trie_node holding the value
 * @param key the key where `value` is set
 * @return `value` if exists, `NULL` otherwise
 */
void* trie_get (trie_node_t *root, char *key);

/**
 * @brief deletes `key`
 *
 * @param root the trie_node holding the key
 * @param key the `key` to delete
 * @return true if successful
 */
bool trie_delete (trie_node_t *root, char *key);

#endif /* MONKEYBAR_COMPONENT_H */
