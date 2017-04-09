#ifndef MONKEYBAR_WINDOW_H
#define MONKEYBAR_WINDOW_H

#include <stdio.h>
#include <xcb/xcb.h>

typedef struct mb_window_s {
  xcb_connection_t *connection;
  xcb_screen_t     *screen;
  xcb_drawable_t   *drawable;
  char             *name;
} mb_window_t;

#endif /* MONKEYBAR_WINDOW_H */
