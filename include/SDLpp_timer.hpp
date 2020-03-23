#ifndef SDLPP_TIMER_HPP
#define SDLPP_TIMER_HPP

#include <cstdint>

namespace sdl
{
	class timer;
}

class sdl::timer
{
	public:
	timer() noexcept;
	
	void start();
	void stop();
	
	uint32_t ticks();
	
	bool is_started();
	
	private:
	bool started_;
	uint32_t start_time_;
	
};

#endif