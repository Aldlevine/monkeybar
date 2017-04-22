#ifndef MONKEYBAR_EVENT_CALLBACK_H
#define MONKEYBAR_EVENT_CALLBACK_H

#include "event.h"

typedef void (* EventCallbackFunction)(Event *);

typedef struct EventCallback_s {
  uint16_t id;
  EventCallbackFunction function;
} EventCallback;

EventCallback* event_callback_create (EventCallbackFunction function);

void event_callback_execute (EventCallback *callback, Event *event);

#endif /* MONKEYBAR_EVENT_CALLBACK_H */
