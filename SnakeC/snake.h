/*
 * interface class Snake
 * sebgai sub-class dari Entity
 *
 * Snake adalah karakter utama dalam game. 
 * Snake terdiri dari rangkaian Segment.
*/

#pragma once

#include <vector>

#include "segment.h"
#include "global.h"
#include "fruit.h"

class Snake
{
public:
	Snake();
	Snake(const int, const int, const int);
	bool eat(Fruit&);
	bool hit();
	void reset(const int, const int);
	void locate(const int, const int);
	void move(const Direction);
	void show();

private:
	int num;
	std::vector<Segment> segments;
};