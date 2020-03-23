#ifndef SDLPP_HPP
#define SDLPP_HPP

#include "SDLpp_surface.hpp"
#include "SDLpp_window.hpp"
#include "SDLpp_renderer.hpp"
#include "SDLpp_texture.hpp"
#include "SDLpp_font.hpp"
#include "SDLpp_timer.hpp"

#include <SDL.h>
#include <SDL_ttf.h>
#include <cstdint>

namespace sdl
{
	void init(uint32_t flags = SDL_INIT_EVERYTHING);
	void quit();
}

#endif