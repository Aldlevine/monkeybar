/* #include "component_s.h" */
#include "component.h"

Component *
component_create (char *type)
{
  Component *component = malloc(sizeof(Component));
  component->type = type;
  component->properties = dictionary_create();
  component->event_target = event_target_create();
  return component;
}

void
component_free (Component *component)
{
  event_target_free(component->event_target);
  free(component);
}
