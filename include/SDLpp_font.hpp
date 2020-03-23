#ifndef SDLPP_FONT_HPP
#define SDLPP_FONT_HPP

#include <SDL_ttf.h>
#include <string>

namespace sdl
{
	class font;
}

class sdl::font
{
	public:
	font(const std::string &path, int sz);
	
	~font();
	
	TTF_Font *get() const noexcept;
		
	operator TTF_Font *() const noexcept;
	
	private:
	TTF_Font *f_;
};

#endif