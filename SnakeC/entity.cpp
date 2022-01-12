/*
 * implementasi class Entity
 * berisi data x,y dan fungsi-fungsi untuk mengaksesnya.
*/

#include "entity.h"

void Entity::set_x(const int _x)
{
	x = _x <= 0 ? 0 : _x;
}

void Entity::set_y(const int _y)
{
	y = _y <= 0 ? 0 : _y;
}

int Entity::get_x() const
{
	return x;
}

int Entity::get_y() const
{
	return y;
}