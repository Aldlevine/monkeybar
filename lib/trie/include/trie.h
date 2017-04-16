/**
 * @file trie.h
 */

#ifndef  MONKEYBAR_TRIE_H
#define  MONKEYBAR_TRIE_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct TrieNode_s TrieNode;

/**
 * @brief creates a `TrieNode` to use as a root node
 *
 * @return a `TrieNode` root node
 */
TrieNode *trie_create (void);

/**
 * @brief frees a `TrieNode` and all of its children
 *
 * @param node the trie to free
 */
void trie_free (TrieNode *node);

/**
 * @brief sets `key` to `value`
 *
 * @param root the `TrieNode` to insert into
 * @param key the key to set
 * @param value the value to set `key` to
 * @return `true` if successful, `false` otherwise
 */
bool  trie_set (TrieNode *root, char *key, void *value);

/**
 * @brief gets `value` at `key`
 *
 * @param root the `TrieNode` holding the value
 * @param key the key where `value` is set
 * @return `value` if exists, `NULL` otherwise
 */
void* trie_get (TrieNode *root, char *key);

/**
 * @brief deletes `key`
 *
 * @param root the `TrieNode` holding the key
 * @param key the `key` to delete
 * @return true if successful
 */
bool trie_delete (TrieNode *root, char *key);

#endif /* MONKEYBAR_COMPONENT_H */
