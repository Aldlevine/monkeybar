/**
 * @internal
 * @file trie.c
 */

#include "trie.h"


#define special_count  3
#define lower_offset   (('Z' - 'A') + 1)
#define number_offset  (lower_offset + ('z' - 'a') + 1)
#define special_offset (number_offset + ('9' - '0'))
#define addr_count     (special_offset + special_count)


/**
 * @brief a struct that manages traversing a trie
 */
typedef struct trie_node_s {
  void               *value;
  struct trie_node_s *children[addr_count];
  bool               has_value;
  uint8_t            num_children;
} trie_node_t;


/**
 * @brief sets the value of a trie_node
 *
 * @param node the node to have it's value set
 * @param value the value to set it to
 */
static void
trie_node_set (trie_node_t *node, void *value)
{
  node->has_value = true;
  node->value = value;
}


/**
 * @brief unsets a trie_node's value.
 * if the node has no children it will be freed also
 *
 * @param node the node to unset
 */
static void
trie_node_unset (trie_node_t *node)
{
  node->has_value = false;

  if (node->value != NULL) {
    node->value = NULL;
  }
  if (node->num_children == 0) {
    free(node);
  }
}


/**
 * @brief adds a new trie_node to another trie_node at a given address
 *
 * @param node the node to be added to
 * @param new the new node to add
 * @param addr the address on `node` where `new` will be added
 */
static void
trie_node_add (trie_node_t *node, trie_node_t *new, uint8_t addr)
{
  node->children[addr] = new;
  node->num_children++;
}


/**
 * @brief removes a trie_node at a given address
 *
 * @param node the node to remove the child from
 * @param addr the address of the child
 */
static void
trie_node_remove (trie_node_t *node, uint8_t addr)
{
  trie_node_unset(node->children[addr]);
  node->num_children--;
}


/**
 * @brief computes a trie_node address from a given character
 * if the character is valid, returns true otherwise false
 *
 * @param chr the character to compute an address for
 * @param addr a pointer where the address will be stored
 */
static bool
trie_node_addr (char chr, uint8_t *addr)
{
  /* A - Z */
  if (chr >= 'A' && chr <= 'Z') {
    *addr = chr - 'A';
    return true;
  }

  /* a - z */
  if (chr >= 'a' && chr <= 'z') {
    *addr = lower_offset + (chr - 'a');
    return true;
  }

  /* 0 - 9 */
  if (chr >= '0' && chr <= '9') {
    *addr = number_offset + (chr - '0');
    return true;
  }

  /* $ */
  if (chr == '$') {
    *addr = special_offset + 1;
    return true;
  }
  /* - */
  if (chr == '-') {
    *addr = special_offset + 2;
    return true;
  }
  /* _ */
  if (chr == '_') {
    *addr = special_offset + 3;
    return true;
  }

  return false;
}


trie_node_t *
trie_create ()
{
  trie_node_t *node = malloc(sizeof(trie_node_t));
  memset(node->children, 0, sizeof(trie_node_t));
  node->num_children = 0;
  node->has_value = false;
  return node;
}

void
trie_free (trie_node_t *node)
{
  trie_node_t *child = node;
  uint8_t i;
  for (i=0; i<addr_count && node->num_children > 0; ++i) {
    child = child->children[i];
    if (child == NULL) {
      continue;
    }
    trie_free(child);
  }
  free(node);
}

bool
trie_set (trie_node_t *root, char *key, void *value)
{
  char addr_char;
  uint8_t addr;
  uint8_t i = 0;
  trie_node_t *node = root;

  while ((addr_char = key[i++]) != '\0') {
    if ( trie_node_addr(addr_char, &addr) ) {
      if (node->children[addr] == NULL) {
        node->children[addr] = trie_create();
      }
      node = node->children[addr];
      continue;
    }
    return false;
  }

  trie_node_set(node, value);
  return true;
}

void *
trie_get (trie_node_t *root, char *key)
{
  char addr_char;
  uint8_t addr;
  uint8_t i = 0;
  trie_node_t *node = root;

  while ((addr_char = key[i++]) != '\0') {
    if (trie_node_addr(addr_char, &addr)) {
      if (node->children[addr] == NULL) {
        return NULL;
      }
      node = node->children[addr];
      continue;
    }
    return NULL;
  }
  if (node->has_value) {
    return node->value;
  }
  return NULL;
}

bool
trie_delete (trie_node_t *root, char *key)
{
  char addr_char;
  uint8_t addr;
  uint8_t i = 0;
  trie_node_t *node = root;

  while ((addr_char = key[i++]) != '\0') {
    if (trie_node_addr(addr_char, &addr)) {
      if (node->children[addr] == NULL) {
        return true;
      }
      node = node->children[addr];
      continue;
    }
    return false;
  }
  trie_node_unset(node);
  return true;
}
