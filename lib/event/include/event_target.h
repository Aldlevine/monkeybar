#ifndef MONKEYBAR_EVENT_TARGET_H
#define MONKEYBAR_EVENT_TARGET_H

#include <stdbool.h>

#include "event.h"
#include "event_callback.h"
#include "vector/vector.h"

typedef struct _EventTarget_s EventTarget;

/**
 * creates an event target
 *
 * @return  the newly created event target
 */
EventTarget * event_target_create ();

/**
 * frees an event target
 *
 * @param   event_target  the event target to free
 */
void event_target_free (EventTarget *event_target);

/**
 * adds registers a callback function for an event on an event target
 *
 * @param   event_target  the target on which to register the event callback
 * @param   type          the type of event for which to register
 * @param   callback      the callback function to register
 * @return                the id of the callback registered
 */
uint16_t event_target_add_event (EventTarget *event_target, char *type, EventCallbackFunction callback);

/**
 * removes a callback function for an event from an event target
 *
 * @param   event_target  the event target from which to remove
 * @param   type          the type of event from which to remove
 * @param   id            the id of the event callback
 * @return                true if event callback exists, false otherwise
 */
bool event_target_remove_event (EventTarget *event_target, char *type, uint16_t id);

/**
 * emits an event for an event target
 *
 * @param   event_target  the event target for which to emit the event
 * @param   event         the event to emit
 * @return                true if successful, false otherwise
 */
bool event_target_emit_event (EventTarget *event_target, Event *event);

#endif /* MONKEYBAR_EVENT_TARGET_H */
