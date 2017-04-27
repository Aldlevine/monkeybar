#ifndef MONKEYBAR_COMPONENT_S_H
#define MONKEYBAR_COMPONENT_S_H

#include "dictionary/dictionary.h"
#include "event/event.h"

struct _Component_s {
  EventTarget *event_target;
  char        *type;
  Dictionary  *properties;
};

#endif /* MONKEYBAR_COMPONENT_S_H */
