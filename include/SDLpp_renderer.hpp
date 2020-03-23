#ifndef SDLPP_RENDERER_HPP
#define SDLPP_RENDERER_HPP

#include <SDL.h>
#include <cstdint>

#include "SDLpp_window.hpp"

namespace sdl
{
	class renderer;
}

class sdl::renderer
{		
	public:
	// constructor from args
	// w: * to SDL_Window for which the rendering context is for
	// index: index of the rendering driver to initialize, -1 for the first
	//        one supporting the requested flags
	// flags: 0, or one or more SDL_RendererFlags OR'd together
		explicit renderer(SDL_Window *w, int index = -1, uint32_t flags = 0);
		
	// copy and move
		renderer(const renderer &) = delete;
		renderer &operator=(const renderer &) = delete;
		renderer(renderer &&rhs);
		renderer &operator=(renderer &&rhs);
	
	// destructor
		~renderer();
		
		SDL_Renderer *get() const noexcept;
		
		operator SDL_Renderer *() const noexcept;
		
	private:
		SDL_Renderer *_ren;
};

#endif