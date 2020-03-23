#ifndef SDLPP_WINDOW_HPP
#define SDLPP_WINDOW_HPP

#include <string>
#include <cstdint>
#include <SDL.h>
#include <memory>

namespace sdl
{
	class window;
}

class sdl::window
{
	public:
	// constructors via args
		explicit window(const std::string &name = "SDL", 
			   const uint32_t x = SDL_WINDOWPOS_CENTERED, 
			   const uint32_t y = SDL_WINDOWPOS_CENTERED, 
			   const int w = _default_w, 
			   const int h = _default_h, 
			   const uint32_t flags = SDL_WINDOW_SHOWN);
		window(const std::string &name, const int w, const int h);
		window(const std::string &name, const uint32_t flags);
	
	// copy and move
		window(const window &w) = delete;
		window &operator=(const window &w) = delete;
		window(window &&w);
		window &operator=(window &&w);
		
	// destructor
		~window();
		
		SDL_Window *get() const noexcept;
		operator SDL_Window *() const noexcept;
		
	private:
		static constexpr int _default_w = 640;
		static constexpr int _default_h = 480;
		SDL_Window *_win;
};

#endif