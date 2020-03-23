#include "SDLpp.hpp"

#include <exception>
#include <string>
#include <cstdlib>

void sdl::init(uint32_t flags)
{
	if (SDL_Init(flags) != 0)
	{
		std::string err {"Could not initialize SDL! Error: "};
		std::string e {SDL_GetError()};
		throw std::runtime_error {err + e};
	}
	if (TTF_Init() != 0)
	{
		std::string err {"Could not initialize TTF! Error: "};
		std::string e {TTF_GetError()};
		throw std::runtime_error {err + e};
	}
	std::atexit(sdl::quit);
}

void sdl::quit()
{
	SDL_Quit();
	TTF_Quit();
}