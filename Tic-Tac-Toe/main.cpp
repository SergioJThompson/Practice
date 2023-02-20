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


    SDL_Surface* sprite_surface = IMG_Load("/Users/sergiojthompson/Programs/C++/Tic-Tac-Toe/images/x.jpg");

    Object squareA1(sprite_surface, 0, 159);
    Object squareB1(sprite_surface, 0, 300);
    Object squareC1(sprite_surface, 0, 450);

    Object square_arr[3] = {
        squareA1, squareB1, squareC1
    };

    loop(window, image_surface, square_arr, 3);

    SDL_FreeSurface(image_surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
