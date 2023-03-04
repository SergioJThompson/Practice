#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "object.cpp"

void loop(SDL_Window *window, SDL_Surface *image_surface, Object square_arr[], int arr_size) {
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
        // toggle image state of each object
        for (int i = 0; i < arr_size; i++) {
            square_arr[i].toggleImage();
        }

        // clear the surface
        SDL_FillRect(SDL_GetWindowSurface(window), nullptr, SDL_MapRGB(SDL_GetWindowSurface(window)->format, 255, 255, 255));

        // blit the background image onto the window surface
        SDL_BlitSurface(image_surface, nullptr, SDL_GetWindowSurface(window), nullptr);

        for (int i = 0; i < arr_size; i++) {
            square_arr[i].draw(SDL_GetWindowSurface(window));
        }
        SDL_UpdateWindowSurface(window);
    }
}

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Failed to initialize the SDL2 library\n";
        return -1;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cout << "Failed to initialize SDL_image\n";
        return -1;
    }

    SDL_Surface *image_surface = IMG_Load("/Users/sergiojthompson/Programs/C++/Tic-Tac-Toe/images/grid.jpg");

    if (!image_surface) {
        std::cout << "Failed to load image\n";
        return -1;
    }

    int image_w = image_surface->w;
    int image_h = image_surface->h;

    SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          image_w, image_h,
                                          SDL_WINDOW_SHOWN);

    if (!window) {
        std::cout << "Failed to create window\n";
        return -1;
    }


    SDL_Surface* sprite_surface = IMG_Load("/Users/sergiojthompson/Programs/C++/Tic-Tac-Toe/images/x.png");

    Object squareA1(sprite_surface, 2, 168);
    Object squareA2(sprite_surface, 2, 328);
    Object squareA3(sprite_surface, 2, 490);

    Object squareB1(sprite_surface, 168, 161);
    Object squareB2(sprite_surface, 168, 328);
    Object squareB3(sprite_surface, 168, 490);

    Object squareC1(sprite_surface, 335, 161);
    Object squareC2(sprite_surface, 335, 328);
    Object squareC3(sprite_surface, 335, 490);

    Object square_arr[9] = {
        squareA1, squareA2, squareA3,
        squareB1, squareB2, squareB3,
        squareC1, squareC2, squareC3
    };

    loop(window, image_surface, square_arr, 9);

    SDL_FreeSurface(image_surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
