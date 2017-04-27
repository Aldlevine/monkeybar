#include "event_s.h"
#include "event_target.h"
#include "event_target_s.h"

EventTarget *
event_target_create ()
{
  EventTarget *event_target = malloc(sizeof(EventTarget));
  event_target->events      = dictionary_create(NULL);
  return event_target;
}

void
event_target_free (EventTarget *event_target)
{
  free(event_target);
}

uint16_t
event_target_add_event (EventTarget *event_target, char *type, EventCallbackFunction callback)
{
  static uint16_t id = 0;
  Vector *events = dictionary_get(event_target->events, type);
  EventCallback *event_callback = event_callback_create(callback);
  event_callback->id = id;
  if (events == NULL)
  {
    events = vector_create(1, event_callback);
    dictionary_set(event_target->events, type, events);
  }
  else
  {
    vector_push(events, event_callback);
  }
  return id++;
}

#include <stdio.h>
bool
event_target_remove_event (EventTarget *event_target, char *type, uint16_t id)
{
  Vector *events = dictionary_get(event_target->events, type);
  if (events == NULL)
  {
    return false;
  }
  EventCallback *event_callback;
  size_t idx = 0;
  VECTOR_EACH (events, data)
  {
    event_callback = (EventCallback *)(data);
    if (event_callback->id == id)
    {
      Vector *tmp = vector_extract(events, idx, 1);
      event_callback_free(event_callback);
      vector_free(tmp);
      return true;
    }
    idx++;
  }
  END_VECTOR_EACH;
  return false;
}

bool
event_target_emit_event (EventTarget *event_target, Event *event)
{
  Vector *events = dictionary_get(event_target->events, event->type);
  EventCallback *callback;

  if (events == NULL)
  {
    return false;
  }

  VECTOR_EACH (events, callback)
  {
    event_callback_execute(callback, event);
    if (event->cancelled)
    {
      break;
    }
  }
  END_VECTOR_EACH;

  return true;
}
