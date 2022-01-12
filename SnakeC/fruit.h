/*
 * interface class Fruit
 * sebagai sub-class dari Entity
 *
 * Fruit adalah makanan Snake
*/

#pragma once

#include "entity.h"

class Fruit: public Entity
{
public:
	Fruit();
	Fruit(const int, const int);
	void live();
	void reset();
	void show();

private:
	float life;		// usia fruit
	int chr;		// karakter untuk menggambar fruit
};