#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

enum ImageState : int { Empty, X, O };

class Object {
public:
    Object(SDL_Surface *surface, int x, int y) : m_surface(surface), m_x(x), m_y(y), m_imageState(Empty) {}


    void draw(SDL_Surface *surface) {
        if (m_imageState != Empty) {
            SDL_Rect rect = {m_x, m_y, m_surface->w, m_surface->h};
            SDL_BlitSurface(m_surface, nullptr, surface, &rect);
        }
    }

    void toggleImage() {
        switch (m_imageState) {
            case X:
                m_surface = IMG_Load("/Users/sergiojthompson/Programs/C++/Tic-Tac-Toe/images/o.png");
                m_imageState = O;
                break;
            case O:
                m_imageState = Empty;
                break;
            case Empty:
                m_surface = IMG_Load("/Users/sergiojthompson/Programs/C++/Tic-Tac-Toe/images/x.png");
                m_imageState = X;
                break;
            default:
                break;
        }
    }

    void toggleImage(ImageState s) {
        switch (s) {
            case X:
                m_surface = IMG_Load("/Users/sergiojthompson/Programs/C++/Tic-Tac-Toe/images/x.png");
                m_imageState = X;
                break;
            case O:
                m_surface = IMG_Load("/Users/sergiojthompson/Programs/C++/Tic-Tac-Toe/images/o.png");
                m_imageState = O;
                break;
            case Empty:
                m_imageState = Empty;
            default:
                break;
        }
    }

private:
    SDL_Surface *m_surface;
    int m_x, m_y;
    ImageState m_imageState;
};
