#pragma once

#include <SFML\Graphics.hpp>

class Entity
{
public:
	virtual void set_x(const int);
	virtual void set_y(const int);
	virtual int get_x();
	virtual int get_y();
	virtual void show(sf::RenderTarget& t) = 0;

protected:
	int _x;
	int _y;
};