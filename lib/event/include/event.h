#ifndef MONKEYBAR_EVENT_H
#define MONKEYBAR_EVENT_H

#include <stdbool.h>
#include "dictionary/dictionary.h"

typedef struct _Event_s Event;

/**
 * creates a new event
 *
 * @param   type         the event type
 * @param   data         the data the event has
 * @param   cancellabel  whether or not the event can be cancelled
 * @return               a newly created event
 */
Event * event_create (char *type, Dictionary *data, bool cancellable);

/**
 * frees an event
 *
 * @param  event  the event to be freed
 */
void event_free (Event *event);

/**
 * cancels an event if cancellable
 *
 * @param   event  the event to cancel
 * @return         true if cancelled, false otherwise
 */
bool event_cancel (Event *event);

/**
 * gets the event type from an event
 *
 * @param   event  the event from which to get the type
 * @return         the event's type
 */
char * event_type (Event *event);

/**
 * gets the data from an event
 *
 * @param   event  the event from which to get the data
 * @return         the event's data
 */
Dictionary * event_data (Event *event);

#endif /* MONKEYBAR_EVENT_H */
