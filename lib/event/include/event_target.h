#include "trie.h"
#include "event.h"

typedef struct event_target_s {
  char        *type;
  trie_node_t *properties;
} event_target_t;

event_target_t *event_target_create (char *type, trie_node_t *properties);
void event_target_free (event_target_t *event_target);
bool event_target_register_event (char *type/*, ... */);
bool event_target_emit_event (event_t *event);
bool event_target_handle_event (event_t *event);
