#include "SDLpp_surface.hpp"

#include <stdexcept>
#include <SDL_image.h>

using sdl::surface;

// invariant: sur_ always points to an SDL_Surface 
// construct from image path
surface::surface(const std::string &path)
	: sur_ {IMG_Load(path.c_str())}
{
	if (sur_ == nullptr)
		throw std::runtime_error {std::string {"Could not create surface! \
			Error: "} + IMG_GetError()};
}

// move constructor
surface::surface(surface &&rhs)
	: sur_ {rhs.sur_}
{
	rhs.sur_ = nullptr;
}

// move assignment
surface &surface::operator=(surface &&rhs)
{
	std::swap(sur_, rhs.sur_);
	return *this;
}

// destructor
// check for nullptr just in case
surface::~surface()
{
	if (sur_ != nullptr)
		SDL_FreeSurface(sur_);
}

// return const pointer, but the data pointed to (must) be mutable for the
// SDL library
SDL_Surface *surface::get() const noexcept
{
	return sur_;
}

// conversion operator
surface::operator SDL_Surface *() const noexcept
{
	return sur_;
}
