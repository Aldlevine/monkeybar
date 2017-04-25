#ifndef MONKEYBAR_COMPONENT_S_H
#define MONKEYBAR_COMPONENT_S_H

#include "dictionary/dictionary.h"
#include "event/event.h"

struct _Component_s {
  char        *type;
  Dictionary  *properties;
  EventTarget *event_target;
};

#endif /* MONKEYBAR_COMPONENT_S_H */
