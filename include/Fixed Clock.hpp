#ifndef FIXED_CLOCK_HPP
#define FIXED_CLOCK_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

class FixedClock {
	sf::Clock clock;
	bool clock_flag = true;
public:
	float getElapsedTime() { if (clock_flag) { clock.restart(); clock_flag = false; } return clock.getElapsedTime().asSeconds(); }
	void restart() { clock.restart(); clock_flag = true; }
};
#endif