#include "event.h"
#include "event_s.h"

typedef struct _Event_s Event;

Event *
event_create (char *type, Dictionary *data, bool cancellable)
{
  Event *event = malloc(sizeof(Event));
  event->type = type;
  event->data = data;
  event->cancellable = cancellable;
  return event;
}

void
event_free (Event *event)
{
  free(event);
}

bool
event_cancel (Event *event)
{
  if (event->cancellable)
  {
    return event->cancelled = true;
  }
  return false;
}

char *
event_type (Event *event)
{
  return event->type;
}

Dictionary *
event_data (Event *event)
{
  return event->data;
}
