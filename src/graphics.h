#ifndef CE_GRAPHICS_H
#define CE_GRAPHICS_H

#include <SDL2/SDL.h>

/**
 * Graphic struct.
 */
typedef struct {
    char *w_title;
    int w_width;
    int w_height;
    SDL_Window *window;
} ce_Graphics;

/**
 * Graphics interface.
 */
int ce_graphics_init(ce_Graphics *graphics, char *title, int *width, int *height);
void ce_graphics_destroy(ce_Graphics *graphics);

#endif