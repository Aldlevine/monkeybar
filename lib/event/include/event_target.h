#ifndef MONKEYBAR_EVENT_TARGET_H
#define MONKEYBAR_EVENT_TARGET_H

#include <stdbool.h>

#include "dictionary/dictionary.h"
#include "event.h"
#include "event_callback.h"

typedef struct EventTarget_s {
  uint8_t      id;
  char         *type;
  Dictionary   *properties;
  Dictionary   *events;
} EventTarget;

EventTarget* event_target_create (char *type, Dictionary *properties);

void event_target_free (EventTarget *event_target);

uint16_t event_target_insert_event (EventTarget *event_target, char *type, EventCallback event_callback);

bool event_target_remove_event (EventTarget *event_target, uint16_t id);

bool event_target_emit_event (EventTarget *event_target, Event *event);

bool event_target_handle_event (EventTarget *event_target, Event *event);

#endif /* MONKEYBAR_EVENT_TARGET_H */
