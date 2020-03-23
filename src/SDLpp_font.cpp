#include "SDLpp_font.hpp"
#include <stdexcept>
#include <string>

using sdl::font;

font::font(const std::string &path, int sz)
	: f_ {TTF_OpenFont(path.c_str(), sz)}
{
	if (!f_)
		throw std::runtime_error {std::string {"Could not open font! \
			SDL_ttf Error: "} + TTF_GetError()};
}

font::~font()
{
	if (f_)
		TTF_CloseFont(f_);
}

TTF_Font *font::get() const noexcept
{
	return f_;
}

font::operator TTF_Font *() const noexcept
{
	return f_;
}