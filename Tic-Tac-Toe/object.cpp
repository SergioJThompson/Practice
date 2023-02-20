#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Object {
    public:
        Object(SDL_Surface *surface, int x, int y) : m_surface(surface), m_x(x), m_y(y) {}

        void draw(SDL_Surface *surface) {
            SDL_Rect rect = {m_x, m_y, m_surface->w, m_surface->h};
            SDL_BlitSurface(m_surface, nullptr, surface, &rect);
        }

    private:
        SDL_Surface *m_surface;
        int m_x, m_y;
};
