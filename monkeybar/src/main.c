#include <stdio.h>
#include <xcb/xcb.h>

#include "loldog.h"
#include "config.h"

#include "trie/trie.h"
#include "dictionary/dictionary.h"
#include "event/event.h"

int main ( int argc, char *argv[] )
{
  /* Print version */
  LOLDOG(LOLDOG_DEBUG, "Monkeybar Version: %s\n", MONKEYBAR_VERSION);

  xcb_connection_t *con = xcb_connect(NULL, NULL);
  xcb_disconnect(con);

  return 0;
}
