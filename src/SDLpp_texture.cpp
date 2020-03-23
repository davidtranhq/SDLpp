#include "SDLpp_texture.hpp"

#include <stdexcept>

using sdl::texture;
static std::string err_msg {"Could not create texture! Error: :"};

// constructor from args, creates a texture for a rendering context
texture::texture(SDL_Renderer *ren, uint32_t fmt, const int access, 
	const int w, const int h)
	: tex_ {SDL_CreateTexture(ren, fmt, access, w, h)}
{
	if (!tex_)
		throw std::runtime_error {err_msg + SDL_GetError()};
}

// converts an SDL_Surface to an SDLtex_ture
texture::texture(SDL_Renderer *ren, SDL_Surface *s)
	: tex_ {SDL_CreateTextureFromSurface(ren, s)}
{
	if (!tex_)
		throw std::runtime_error {err_msg + SDL_GetError()};
}


// creates a texture given an image path
texture::texture(SDL_Renderer *ren, const std::string &file)
	: texture(ren, sdl::surface(file).get())
{
}

// create texture from text string
texture::texture(SDL_Renderer *ren, const std::string &s, TTF_Font *f, 
	SDL_Color c)
	: texture(ren, TTF_RenderText_Solid(f, s.c_str(), c))
{
	if (!tex_)
		throw std::runtime_error {err_msg + SDL_GetError()};
}

texture::texture(texture &&rhs)
	: tex_ {rhs.tex_}
{
	rhs.tex_ = nullptr;
}

texture &texture::operator=(texture &&rhs)
{
	SDL_DestroyTexture(tex_);
	tex_ = rhs.tex_;
	rhs.tex_ = nullptr;
	return *this;
}

texture::~texture()
{
	if (tex_)
		SDL_DestroyTexture(tex_);
}

SDL_Texture *texture::get() const noexcept
{
	return tex_;
}

texture::operator SDL_Texture *() const noexcept
{
	return tex_;
}