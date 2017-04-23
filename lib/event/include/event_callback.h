#ifndef MONKEYBAR_EVENT_CALLBACK_H
#define MONKEYBAR_EVENT_CALLBACK_H

#include "event.h"

typedef void (* EventCallbackFunction)(Event *);

typedef struct EventCallback_s {
  uint16_t id;
  EventCallbackFunction function;
} EventCallback;

/**
 * creates an event callback
 *
 * @param   function  the function the event callback executes
 * @return            the newly created event callback
 */
EventCallback * event_callback_create (EventCallbackFunction function);

/**
 * frees an event callback
 *
 * @param  event_callback  the event callback to free
 */
void event_callback_free (EventCallback *event_callback);

/**
 * executes an event callback with a given event
 *
 * @param  event_callback  the event callback to execute
 * @param  event           the event to pass into the callback
 */
void event_callback_execute (EventCallback *event_callback, Event *event);

#endif /* MONKEYBAR_EVENT_CALLBACK_H */
