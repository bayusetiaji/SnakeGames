#pragma once

#include "Entity.h"

class Segment : public Entity
{
public:
	Segment();
	Segment(const int, const int);
	void save_prev_xy();
	void follow(const Segment&);
	void show(sf::RenderTarget&);
	void grid_to_pix();

private:
	void _init_shp();

	int _px;
	int _py;
	sf::RectangleShape _shp;
};