/*
 * implementasi class Segment
 *
*/

#include "segment.h"

// default constructor

Segment::Segment() : px{ 0 }, py{ 0 }
{
	x = 0;
	y = 0;
}

// constructor
// parameter:
//   - _x: posisi x awal
//   - _y: posisi y awal

Segment::Segment(const int _x, const int _y) : px{ _x }, py{ _y }
{
	x = _x;
	y = _y;
}

// fungsi: save_prev_xy()
//   menyimpan posisi x, y sebemlunya ke dalam px, py
// parameter: -
// kembalian: void

void Segment::save_prev_xy()
{
	px = x;
	py = y;
}

// fungsi: follow()
//   mengikuti jejak Segment lain yang di depan dengan cara
//   mengambil nilai px, py Segment sebelumnya kemudian disimpan
//   dalam x, y
// paramater:
//   - S: Segment&
// kembalian: void

void Segment::follow(Segment& s)
{
	save_prev_xy();
	x = s.px;
	y = s.py;
}
