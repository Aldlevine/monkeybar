#ifndef MONKEYBAR_EVENT_S_H
#define MONKEYBAR_EVENT_S_H

#include <stdbool.h>

#include "dictionary/dictionary.h"

typedef struct _Event_s {
  char         *type;
  Dictionary   *data;
  bool         cancellable;
  bool         cancelled;
} Event;

#endif /* MONKEYBAR_EVENT_S_H */
