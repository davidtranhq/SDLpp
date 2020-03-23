#ifndef SDLPP_TEXUTRE_HPP
#define SDLPP_TEXTURE_HPP

#include "SDLpp_surface.hpp"

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <cstdint>

namespace sdl
{
	class texture;
}

class sdl::texture
{
	public:
	// constructor from args
	// ren: the rendering context
	// fmt: SDL_PixelFormatEnum (pixel format)
	// access: SDL_TextureAccess (specfies how it can be accessed
		// SDL_CreateTexture
		texture(SDL_Renderer *ren, uint32_t fmt, const int access, 
			const int w, const int h);
		// converts an SDL_Surface to an SDL_Texture
		texture(SDL_Renderer *ren, SDL_Surface *s);
		// creates a texture from an image
		texture(SDL_Renderer *ren, const std::string &file);
		// create texture from text string
		texture(SDL_Renderer *ren, const std::string &s, TTF_Font *f, 
			SDL_Color c);
		
	// copy and move
		texture(const texture &rhs) = delete;
		texture &operator=(const texture &rhs) = delete;
		texture(texture &&rhs);
		texture &operator=(texture &&rhs);
		
	// destructor
		void free();
		~texture();
		
		SDL_Texture *get() const noexcept;
		
		operator SDL_Texture *() const noexcept;
		
	private:
		SDL_Texture *tex_;
};

#endif