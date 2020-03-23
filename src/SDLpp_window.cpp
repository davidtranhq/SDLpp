#include "SDLpp_window.hpp"

#include <stdexcept>

using sdl::window;

// default constructor:
// invariant: _win always points to am SDL_Window *
// throws runtime_error otherwise

window::window(const std::string &name, const uint32_t x, const uint32_t y,
	const int w, const int h, 
	const uint32_t flags)
	: _win {SDL_CreateWindow(name.c_str(), x, y, w, h, flags)}
{
	if (_win == nullptr)
		throw std::runtime_error {std::string {"Couldn't create window! \
			Error: "} + SDL_GetError()};
}

// constructor from name and dimensions
// delegates to default constructor
window::window(const std::string &name, const int w, const int h)
	: window(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h)
{
}

// constructor from name and flags
// delegates to default constructor
window::window(const std::string &name, const uint32_t flags)
	: window(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		_default_w, _default_h, flags)
{
}

// move constructor
// transfers ownership
window::window(window &&rhs)
	: _win {rhs._win}
{
	rhs._win = nullptr;
}

window &window::operator=(window &&rhs)
{
	std::swap(_win, rhs._win);
	return *this;
}

// destructor
// make sure we don't destroy a nullptr
window::~window()
{
	if (_win)
		SDL_DestroyWindow(_win);
}

// getter
// so the user can always use native SDL functions without having to implement
// all of them into this class
SDL_Window *window::get() const noexcept
{
	return _win;
}


// conversion operator
// so the user can use this class in native SDL functions as if it were an
// SDL_Window *
window::operator SDL_Window *() const noexcept
{
	return _win;
}
	