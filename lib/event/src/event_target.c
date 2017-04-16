#include "event_target.h"

EventTarget*
event_target_create (char *type, Dictionary *properties)
{
  static uint8_t id = 0;
  EventTarget *event_target = malloc(sizeof(EventTarget));
  event_target->id = id++;
  event_target->type = type;
  event_target->properties = properties;
  /* return EventTarget; */
}
