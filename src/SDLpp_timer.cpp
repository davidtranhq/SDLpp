#include "SDLpp_timer.hpp"

#include <SDL.h>

using sdl::timer;

timer::timer() noexcept
	: started_ {false}
{
}

void timer::start()
{
	started_ = true;
	start_time_ = SDL_GetTicks();
}

void timer::stop()
{
	started_ = false;
	start_time_ = 0;
}

uint32_t timer::ticks()
{
	uint32_t time {0};
	if (started_)
	{
		time = SDL_GetTicks() - start_time_;
	}
	return time;
}