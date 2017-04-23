#include "event_callback.h"

EventCallback *
event_callback_create (EventCallbackFunction function)
{
  EventCallback *callback = malloc(sizeof(EventCallback));
  callback->function = function;
  return callback;
}

void
event_callback_free (EventCallback *event_callback)
{
  free(event_callback);
}

void
event_callback_execute (EventCallback *event_callback, Event *event)
{
  (event_callback->function)(event);
}
