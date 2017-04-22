#include "event_target.h"

EventTarget*
event_target_create (char *type, Dictionary *properties)
{
  static uint8_t id = 0;
  EventTarget *event_target = malloc(sizeof(EventTarget));
  event_target->id = id++;
  event_target->type = type;
  event_target->properties = properties;
  event_target->events = dictionary_create();
  return event_target;
}

void
event_target_free (EventTarget *event_target)
{
  free(event_target);
}

uint16_t
event_target_add_event (EventTarget *event_target, char *type, EventCallback *event_callback)
{
  Vector *events = dictionary_get(event_target->events, type);
  if (events == NULL) {
    events = vector_create(1, event_callback);
    dictionary_set(event_target->events, type, events);
    return 0;
  }
  return vector_push(events, event_callback);
}


bool
event_target_emit_event (EventTarget *event_target, Event *event)
{
  Vector *events = dictionary_get(event_target->events, event->type);
  EventCallback *callback;
  if (events == NULL) {
    return false;
  }
  size_t i = 0, length = events->length;
  /** TODO Make this more efficient by creating a vector iterator */
  while (i<length) {
    callback = vector_get(events, i);
    event_callback_execute(callback, event);
    if (event->cancelled) {
      break;
    }
    i++;
  }
  return true;
}
