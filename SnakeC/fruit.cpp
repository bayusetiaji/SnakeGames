/*
 * implementasi class Fruit
 * 
 * catatan:
 * posisi x, y menggunakan satuan grid di mana 1 grid setara
 * dengan 2 karakter yang ditulis berdampingan. 
 * penjelasan:
 *   ukuran font pada layar konsol memiliki dimensi width
 *   yang lebih kecil dibanding height. asusmsi pada game ini
 *   menggunakan font dengan rasio width:height 1:2. Dengan 
 *   kata lain, jika dalam game menggunakan 40x40 grid, maka
 *   ukuran sebenarnya dari konsol adalah 80x40 karakter.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "fruit.h"
#include "box.h"

// default constructor

Fruit::Fruit()
{
	x = 0;
	y = 0;
	life = 1.f;
	chr = 177;
}

// constructor
// parameter:
//   - _x: posisi x awal
//   - _y: posisi y awal

Fruit::Fruit(const int _x, const int _y)
{
	x = _x;
	y = _y;
	life = 1.f;
	chr = 178;
}

// fungsi: reset()
//   mereset state Fruit dengan cara mengacak posisi x dan y
//   dan mengembalikan nilai life
// parameter: -
// kembalian: void

void Fruit::reset()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	x = rand() % 38 + 1;
	y = rand() % 38 + 1;
	life = 1.f;
}

// fungsi: live()
//   update state dari Fruit dengan cara mengurangi
//   life sebesar 0.01f tiap siklus
// parameter: -
// kembalian: void

void Fruit::live()
{
	life -= 0.01f;

	if (life <= 0.f)
		reset();
}

// fungsi: show()
//   menampilkan Fruit pada posisi x, y dengan menulis
//   karakter ASCII 177 dan 178 secara bergantian tiap
//   siklus.
//   catatan:
//     dengan asusmsi rasio font pada layar konsol adalah
//     1:2, maka untuk memperoleh tampilan yang sama sisi,
//     maka karakter ditulis 2x
// parameter: -
// kembalian: void

void Fruit::show()
{
	goto_xy(x * 2, y);
	text_color(12);
	// karakter ditulis 2x agar diperoleh seakan-akan rasio 1:1
	std::cout << char(chr) << char(chr);
	text_color(7);

	if (chr == 178)
		chr = 177;
	else
		chr = 178;
}