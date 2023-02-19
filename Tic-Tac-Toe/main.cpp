#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void loop(SDL_Window *window, SDL_Surface *image_surface) {
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                default:
                    break;
            }
        }
        SDL_BlitSurface(image_surface, nullptr, SDL_GetWindowSurface(window), nullptr);
        SDL_UpdateWindowSurface(window);
    }
}

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Failed to initialize the SDL2 library\n";
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          500, 500,
                                          SDL_WINDOW_SHOWN);

    if (!window) {
        std::cout << "Failed to create window\n";
        return -1;
    }

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);

    if (!window_surface) {
        std::cout << "Failed to get the surface from the window\n";
        return -1;
    }

    SDL_Surface *image_surface = IMG_Load("image.png");
    if (!image_surface) {
        std::cout << "Failed to load image\n";
        return -1;
    }

    loop(window, image_surface);

    SDL_FreeSurface(image_surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
