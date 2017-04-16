#ifndef MONKEYBAR_EVENT_H
#define MONKEYBAR_EVENT_H

#include <stdbool.h>

#include "dictionary"

typedef struct Event_s {
  char         *type;
  bool         cancellable;
  bool         cancelled;
  Dictionary   *data;
} Event;

Event* event_create (char *type, Dictionary *data);

void event_free (Event *event);

bool event_cancel (Event *event);

#endif /* MONKEYBAR_EVENT_H */
