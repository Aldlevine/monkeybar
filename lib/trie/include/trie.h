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

#endif /* MONKEYBAR_COMPONENT_H */
