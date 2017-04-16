#ifndef MONKEYBAR_EVENT_H
#define MONKEYBAR_EVENT_H

#include <stdbool.h>

#include "dictionary.h"

typedef struct event_s {
  char         *type;
  bool         cancellable;
  bool         cancelled;
  dictionary_t *data;
} event_t;

event_t* event_create (char *type, dictionary_t *data);

void event_free (event_t *event);

bool event_cancel (event_t *event);

#endif /* MONKEYBAR_EVENT_H */
