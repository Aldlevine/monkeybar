#include "event_callback.h"

EventCallback*
event_callback_create (EventCallbackFunction function)
{
  EventCallback *callback = malloc(sizeof(EventCallback));
  callback->function = function;
  return callback;
}

void
event_callback_execute (EventCallback *callback, Event *event)
{
  (callback->function)(event);
}
