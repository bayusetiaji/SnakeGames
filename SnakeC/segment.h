/*
 * interface class Segment
 * sebagai sub-class dari Entity
 *
 * Segment digunakan sebagai pembentuk Snake.
 * Sebuah Snake terdiri dari rangkaian Segment
 * yang saling terhubung.
*/

#pragma once

#include "entity.h"

class Segment: public Entity
{
public:
	Segment();
	Segment(const int, const int);
	void save_prev_xy();
	void follow(Segment&);

private:
	// data jejak x dan y:
	int px;
	int py;
};