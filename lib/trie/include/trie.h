#ifndef  MONKEYBAR_TRIE_H
#define  MONKEYBAR_TRIE_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct _trie_node_s trie_node_t;

/**
 * Creates a `trie_node_t` to use as a root node
 *
 * @return : a `trie_node_t` root node
 */
trie_node_t *trie_create (void);

/**
 * Sets `key` to `value`
 *
 * @root   : the `trie_node` to insert into
 * @key    : the key to set
 * @value  : the value to set `key` to
 * @return : `true` if successful, `false` otherwise
 */
bool  trie_set (trie_node_t *root, char *key, void *value);

/**
 * Gets `value` at `key`
 *
 * @root   : the trie_node holding the value
 * @key    : the key where `value` is set
 * @return : `value` if exists, `NULL` otherwise
 */
void* trie_get (trie_node_t *root, char *key);

#endif /* MONKEYBAR_COMPONENT_H */
