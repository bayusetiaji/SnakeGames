#pragma once

#include "entity.h"

#include <SFML\Graphics.hpp>

class Fruit : public Entity
{
public:
	Fruit();
	Fruit(const int, const int);
	void reset();
	void locate(const int, const int);
	void update(const int);
	void show(sf::RenderTarget&);
	sf::CircleShape& get_shp();
	void _init_shp();

private:
	void _grid_to_pix();
	

	sf::CircleShape _shp;
	float _life;
	sf::Time _t_elapsed;
	sf::Clock _clock;
};