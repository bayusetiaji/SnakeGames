#pragma once

#include <vector>
#include <SFML\Graphics.hpp>

#include "segment.h"
#include "fruit.h"

class Snake
{
public:
	Snake();
	Snake(const int, const int, const int);
	void grid_to_pix();
	bool eat(Fruit&);
	bool hit();
	void grow();
	void reset(const int, const int);
	void move(Direction&);
	void update(const int);
	void show(sf::RenderTarget&);

private:
	std::vector<Segment> _segments;
	sf::Time _t_elapsed;
	sf::Clock _clock;
	int _num;
	Direction _dir;
};