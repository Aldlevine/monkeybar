#include "event_target.h"

EventTarget*
event_target_create (char *type, Dictionary *properties)
{
  static uint8_t id = 0;
  EventTarget *event_target = malloc(sizeof(EventTarget));
  event_target->id = id++;
  event_target->type = type;
  event_target->properties = properties;
  return event_target;
}

void
event_target_free (EventTarget *event_target)
{
  free(event_target);
}

uint16_t
event_target_insert_event (EventTarget *event_target, char *type, EventCallback event_callback)
{
  // need simple vector before this can be implemented
}
