#ifndef MONKEYBAR_EVENT_CALLBACK_H
#define MONKEYBAR_EVENT_CALLBACK_H

#include "event.h"

typedef void (* event_callback_function_t)(event_t *);

typedef struct event_callback_s {
  uint16_t id;
  event_callback_function_t function;
} event_callback_t;

void event_callback_execute (event_t *event);

#endif /* MONKEYBAR_EVENT_CALLBACK_H */
