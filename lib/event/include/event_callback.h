#ifndef MONKEYBAR_EVENT_CALLBACK_H
#define MONKEYBAR_EVENT_CALLBACK_H

#include "event.h"

typedef struct event_callback_s {
  uint16_t id;
  void (function *)(event_t *);
} event_callback_t;

void event_callback_execute (event_t *event);

#endif /* MONKEYBAR_EVENT_CALLBACK_H */
