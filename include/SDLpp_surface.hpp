#ifndef SDLPP_SURFACE_HPP
#define SDLPP_SURFACE_HPP

#include <SDL.h>
#include <string>

namespace sdl
{
	class surface;
}

class sdl::surface
{
	public:
	// constructors via args
		explicit surface(const std::string &path);
		surface(SDL_Surface *s);
		
	// copy and move
		surface(const surface &s) = delete;
		surface &operator=(const surface &s) = delete;
		surface(surface &&s);
		surface &operator=(surface &&s);
		
	// destructor
		~surface();
		
		SDL_Surface *get() const noexcept;
		
		operator SDL_Surface *() const noexcept;
		
	private:
		SDL_Surface *sur_;
};
#endif