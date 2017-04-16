#ifndef MONKEYBAR_EVENT_CALLBACK_H
#define MONKEYBAR_EVENT_CALLBACK_H

#include "event.h"

typedef void (* EventCallbackFunction)(Event *);

typedef struct EventCallback_s {
  uint16_t id;
  EventCallbackFunction function;
} EventCallback;

void event_callback_execute (Event *event);

#endif /* MONKEYBAR_EVENT_CALLBACK_H */
