/**
 * @internal
 * @file loldog.h
 */

#ifndef MONKEYBAR_LOLDOG_H
#define MONKEYBAR_LOLDOG_H

#include <stdio.h>
#include <stdlib.h>

#include "config.h"

#define LOLDOG_CRIT  0
#define LOLDOG_ERROR 1
#define LOLDOG_INFO  2
#define LOLDOG_DEBUG 3

#ifdef DISABLE_LOG /* Disable all logging */
#define LOLDOG(lvl, ...) while (0) { (void)(lvl); printf(__VA_ARGS__); }
#else /* DISABLE_LOG */

#ifdef DEBUG /* Debug logging. All logging always on */
#define LOLDOG(lvl, ...) \
do { \
  (void)(lvl); \
  printf(__VA_ARGS__); \
} while (0);

#else /* DEBUG */ /* Environment variable controlled logging */
#define LOLDOG(lvl, ...) \
do { \
  char *s_envlvl = getenv("MONKEYBAR_LOGLEVEL"); \
  int i_envlvl = LOLDOG_CRIT; \
  if ( s_envlvl != NULL ) { \
    i_envlvl = atoi(s_envlvl); \
  } \
  if ( lvl <= i_envlvl ) { \
    printf(__VA_ARGS__); \
  } \
} while (0);

#endif /* DEBUG */
#endif /* DISABLE_LOG */
#endif /* MONKEYBAR_LOLDOG_H */
