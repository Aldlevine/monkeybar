#include <stdio.h>

#include "config.h"

int main ( int argc, char *argv[] )
{
  // Just checking to be sure
  // that my setup compiles correctly
  char *name;
  if ( argc > 1 ) {
    name = argv[1];
  } else {
    name = "World";
  }
  printf("Hello %s\n", name);

  printf("Version %d.%d.%d\n", MONKEYBAR_VERSION_MAJOR,
                               MONKEYBAR_VERSION_MINOR,
                               MONKEYBAR_VERSION_PATCH);

  return 0;
}
