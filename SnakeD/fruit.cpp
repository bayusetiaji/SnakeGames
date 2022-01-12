#include "global.h"
#include "fruit.h"

#include <cstdlib>
#include <ctime>

#include <SFML\Graphics.hpp>

Fruit::Fruit() : _life{ 1.f }, _t_elapsed{sf::Time::Zero}
{
	_x = 0;
	_y = 0;
	_init_shp();
}

Fruit::Fruit(const int x, const int y) : _life{ 1.f }, _t_elapsed{ sf::Time::Zero }
{
	_x = x;
	_y = y;
	_init_shp();
}

void Fruit::reset()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	_x = rand() % num_grid_h + 1;
	_y = rand() % num_grid_v + 1;
	_life = 1.f;
	_t_elapsed = sf::Time::Zero;

	_grid_to_pix();
}

void Fruit::locate(const int x, const int y)
{
	set_x(x);
	set_y(y);
	_grid_to_pix();
}

void Fruit::update(const int elps)
{
	auto t_delta = _clock.restart();
	_t_elapsed += t_delta;

	if (_t_elapsed >= sf::milliseconds(elps))
	{
		_life -= 0.01f;
		_t_elapsed = sf::Time::Zero;
	}

	if (_life <= 0.f)
	{
		reset();
	}
}

void Fruit::show(sf::RenderTarget& t)
{
	t.draw(_shp);
}

void Fruit::_grid_to_pix()
{
	_shp.setPosition(_x * grid_size + world_pad_left, _y * grid_size + world_pad_top);
}

void Fruit::_init_shp()
{
	_shp.setRadius(grid_size / 2);
	_shp.setOrigin(grid_size / 2, grid_size / 2);
	_grid_to_pix();
	_shp.setFillColor(fruit_color);
}

sf::CircleShape& Fruit::get_shp()
{
	return _shp;
}