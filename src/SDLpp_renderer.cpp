#include "SDLpp_renderer.hpp"

#include <stdexcept>
#include <string>

using sdl::renderer;

// constructor from args, in
renderer::renderer(SDL_Window *w, int index, uint32_t flags)
	: _ren {SDL_CreateRenderer(w, index, flags)}
{
	if (_ren == nullptr)
		throw std::runtime_error {std::string {"Could not create renderer! \
			Error: "} + SDL_GetError()};
}

// move constructor
renderer::renderer(renderer &&rhs)
	: _ren {rhs._ren}
{
	rhs._ren = nullptr;
}

// move assignment
renderer &renderer::operator=(renderer &&rhs)
{
	std::swap(_ren, rhs._ren);
	return *this;
}

// destructor, check for nullptr just in case
renderer::~renderer()
{
	if (_ren != nullptr)
		SDL_DestroyRenderer(_ren);
}

// getter
SDL_Renderer *renderer::get() const noexcept
{
	return _ren;
}

// conversion operator
renderer::operator SDL_Renderer *() const noexcept
{
	return _ren;
}

