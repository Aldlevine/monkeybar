#ifndef LOLDOG_H
#define LOLDOG_H

#include <stdio.h>
#include <stdlib.h>

#include "config.h"

enum LolDogLogLevel {
  L_CRIT,
  L_ERROR,
  L_INFO,
  L_DEBUG,
};

#ifdef DISABLE_LOG
#define LOLDOG(lvl, ...)
#else /* DISABLE_LOG */

  #ifdef DEBUG
    #define LOLDOG(lvl, ...) \
    do { \
      printf(__VA_ARGS__); \
    } while (0);
  #else /* DEBUG */
    #define LOLDOG(lvl, ...) \
    do { \
      char *s_envlvl = getenv("MONKEYBAR_LOGLEVEL"); \
      int i_envlvl = L_CRIT; \
      if ( s_envlvl != NULL ) { \
        i_envlvl = atoi(s_envlvl); \
      } \
      if ( lvl <= i_envlvl ) { \
        printf(__VA_ARGS__); \
      } \
    } while (0);
  #endif /* DEBUG */
#endif /* DISABLE_LOG */

#endif /* LOLDOG_H */
