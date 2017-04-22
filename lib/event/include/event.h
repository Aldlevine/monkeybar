#ifndef MONKEYBAR_EVENT_H
#define MONKEYBAR_EVENT_H

#include <stdbool.h>

#include "dictionary/dictionary.h"

typedef struct Event_s {
  char         *type;
  Dictionary   *data;
  bool         cancellable;
  bool         cancelled;
} Event;

Event* event_create (char *type, Dictionary *data, bool cancellable);

void event_free (Event *event);

bool event_cancel (Event *event);

#endif /* MONKEYBAR_EVENT_H */
