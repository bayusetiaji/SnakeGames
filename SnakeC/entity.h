/*
 * interface class Entity
 * sebagai super-class dari Fruit dan Snake
*/

#pragma once

class Entity
{
public:
	virtual void set_x(const int);
	virtual void set_y(const int);
	virtual int get_x() const;
	virtual int get_y() const;

protected:
	int x;
	int y;
};
