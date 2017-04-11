#ifndef MONKEYBAR_EVENT_H
#define MONKEYBAR_EVENT_H

#include <stdbool.h>

#include "trie.h"

typedef struct event_s {
  char        *type;
  bool        cancellable;
  bool        cancelled;
  trie_node_t *data; /* Should hide trie implementation */
} event_t;

event_t* event_create (char *type, trie_node_t *data);

void event_free (event_t *event);

bool event_cancel (event_t *event);

#endif /* MONKEYBAR_EVENT_H */
