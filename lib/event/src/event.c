#include "event.h"

Event *
event_create (char *type, Dictionary *data, bool cancellable)
{
  Event *event = malloc(sizeof(Event));
  event->type = type;
  event->data = data;
  event->cancellable = cancellable;
  return event;
}
