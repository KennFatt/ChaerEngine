#include <SDL2/SDL.h>
#include "graphics.h"

int ce_graphics_init(ce_Graphics *graphics, char *title, int *width, int *height)
{
    graphics->w_title = title;
    graphics->w_width = *width;
    graphics->w_height = *height;

    graphics->window = SDL_CreateWindow(
        graphics->w_title,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        graphics->w_width,
        graphics->w_height,
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    if (graphics->window == NULL) {
        SDL_Log("[ce_Graphics] An error occured while initialize the window: %s\n", SDL_GetError());
        return 1;
    }

    return 0;
}

void ce_graphics_destroy(ce_Graphics *graphics)
{
    SDL_DestroyWindow(graphics->window);
}