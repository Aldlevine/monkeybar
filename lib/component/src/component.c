/* #include "component_s.h" */
#include "component.h"

Component *
component_create (char *type, Dictionary *properties)
{
  if (properties == NULL) properties = dictionary_create(NULL);
  Component *component = malloc(sizeof(Component));
  component->type = type;
  component->properties = properties;
  component->event_target = event_target_create();
  return component;
}

void
component_free (Component *component)
{
  event_target_free(component->event_target);
  free(component);
}

void
component_emit_event (Component *component, Event *event)
{
  dictionary_set(event_data(event), "COMPONENT", component);
  event_target_emit_event(component->event_target, event);
}
