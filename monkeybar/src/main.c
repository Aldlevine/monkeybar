#include <stdio.h>
#include <xcb/xcb.h>

#include "loldog.h"
#include "config.h"

#include "trie/trie.h"
#include "dictionary/dictionary.h"
#include "event/event.h"
#include "component/component.h"

#define ptr2int(x) (int)(intptr_t)x
#define int2ptr(x) (void *)(intptr_t)x

void callback (Event *ev)
{
  printf("Got it\n");
  Dictionary *data = event_data(ev);
  uint8_t x = ptr2int(dictionary_get(data, "pointerx"));
  uint8_t y = ptr2int(dictionary_get(data, "pointery"));
  printf("Position: (%d, %d)\n", x, y);
}

int main (int argc, char *argv[])
{
  /* Print version */
  LOLDOG(LOLDOG_DEBUG, "Monkeybar Version: %s\n", MONKEYBAR_VERSION);

  /* xcb_connection_t *con = xcb_connect(NULL, NULL); */
  /* xcb_disconnect(con); */

  Component *c = component_create ("type");

  Dictionary *data = dictionary_create();
  dictionary_set(data, "pointerx", int2ptr(1));
  dictionary_set(data, "pointery", int2ptr(2));

  Event *event = event_create ("ev1", data, true);

  event_target_add_event  (c->event_target, "ev1", callback);
  event_target_emit_event (c->event_target, event);

  return 0;
}
