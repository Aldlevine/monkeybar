#ifndef MONKEYBAR_EVENT_TARGET_H
#define MONKEYBAR_EVENT_TARGET_H

#include "trie.h"
#include "event.h"

typedef struct event_target_s {
  uint8_t     id;
  char        *type;
  trie_node_t *properties; /* Should hide trie implementation */
  trie_node_t *events; /* Should hide trie implementation */
} event_target_t;

event_target_t* event_target_create (char *type, trie_node_t *properties);

void event_target_free (event_target_t *event_target);

uint16_t event_target_insert_event (char *type/*, event_callback_t */);

bool event_target_remove_event (uint16_t id);

bool event_target_emit_event (event_t *event);

bool event_target_handle_event (event_t *event);

#endif /* MONKEYBAR_EVENT_TARGET_H */
