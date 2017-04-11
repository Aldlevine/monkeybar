#include "trie.h"

typedef struct event_s {
  char        *type;
  trie_node_t *data;
} event_t;

event_t* event_create (char *type, trie_node_t *data);
void event_free (event_t *event);
