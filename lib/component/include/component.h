#ifndef MONKEYBAR_COMPONENT_H
#define MONKEYBAR_COMPONENT_H

#include "dictionary/dictionary.h"
#include "event/event.h"

typedef struct _Component_s {
  EventTarget *event_target;
  char        *type;
  Dictionary  *properties;
} Component;

/**
 * creates an component
 *
 * @return  the newly created component
 */
Component * component_create (char *type);

/**
 * frees an component
 *
 * @param  component  the component to free
 */
void component_free (Component *component);

#endif /* MONKEYBAR_COMPONENT_H */
