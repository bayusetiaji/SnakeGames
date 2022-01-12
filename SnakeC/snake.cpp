/*
* implementasi class Snake
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
#include <vector>
#include <algorithm>
#include <string>
#include <Windows.h>

#include "global.h"
#include "snake.h"
#include "fruit.h"
#include "box.h"

// default constructor
// mendelegasikan ke fungsi reset()

Snake::Snake() : num{ 5 }
{
	reset(0, 0);
}

// constructor
// parameter:
//   - _x: posisi awal x
//   - _y: posisi awal y
//   - _n: jumlah awal Segment
// mendelegasikan ke fungsi reset()

Snake::Snake(const int _x, const int _y, const int _n) : num{ _n } 
{
	reset(_x, _y);
}

// fungsi: hit()
//   mendeteksi apakah Snake menyentuk tepi layar. posisi
//   x, y menggunakan satuan grid.
//   catatan: batasan grid adalah x[2-37], y[4-37]
// parameter: -
// kembalian: bool
//   true: kepala Snake menyentuh tepi atau menyentuh body

bool Snake::hit()
{
	auto& head = segments[0];
	return head.get_x() >= 38 || head.get_x() <= 1 ||
		   head.get_y() >= 38 || head.get_y() <= 3 ||
		   std::find_if(std::begin(segments) + 1, std::end(segments),
		   [&](Segment& s) {													// lambda
				return head.get_x() == s.get_x() && head.get_y() == s.get_y();	// head menyentuh body
		   }) != std::end(segments);
		
}

// fungsi: reset()
//   menambahkan sejumlah n Segment sebagai pembentuk Snake.
//   Segment ke-0 adalah kepala, yang posisi x, y -nya diikuti
//   oleh Segment-Segment lain di belakang. poisis awal Snake 
//   adalah vertikal menghadap atas.
// parameter:
//   - _x: posisi x awal kepala
//   - _y: poisis y awal kepala
// kembalian: void

void Snake::reset(const int _x, const int _y)
{
	segments.clear();
	for (int i = 0; i < num; ++i)
		segments.push_back(Segment{ _x, _y + i });
}

// fungsi: eat()
//   memakan Fruit. Fruit dimakan oleh Snake bila posisi x,y Fruit
//   sama dengan posisi x,y kepala Snake. jika iya, maka Snake akan
//   menambah 1 Segment di belakang.
// parameter:
//   - f: Fruit&
// kembalian: bool
//   true: jika Snake berhasil memakan Fruit

bool Snake::eat(Fruit& f)
{
	if (segments[0].get_x() == f.get_x() && segments[0].get_y() == f.get_y())
	{
		auto& tail = segments[segments.size() - 1];
		segments.push_back(Segment{ tail.get_x(), tail.get_y() });
		return true;
	}
	
	return false;
}

// fungsi: locate()
//   meletakkan kepala Snake pada posisi x,y
// parameter:
//   - _x: posisi x baru
//   - _y: posisi y baru
// kembalian: void

void Snake::locate(const int _x, const int _y)
{
	segments[0].set_x(_x);
	segments[0].set_y(_y);
}

// fungsi: move()
//   mengarahkan kepala Snake sesuai nilai Direction.
//   bila:
//     - Idle : diam
//     - Up   : ke atas
//     - Right: ke kanan
//     - Down : ke bawah
//     - Left : ke kiri
//  pergerakan kepala akan diikuti semua Segment di belakang
//  secara sambung menyambung.
//  parameter:
//    - dir: Direction
//  kembalian: void

void Snake::move(const Direction dir)
{
	auto& head = segments[0];
	head.save_prev_xy();

	if (dir == Direction::Up)
		head.set_y(head.get_y() - 1);
	else if (dir == Direction::Right)
		head.set_x(head.get_x() + 1);
	else if (dir == Direction::Down)
		head.set_y(head.get_y() + 1);
	else if (dir == Direction::Left)
		head.set_x(head.get_x() - 1);

	if (dir != Direction::Idle)
		for (size_t i = 1; i < segments.size(); ++i)
			segments[i].follow(segments[i - 1]);
}

// fungsi: show()
//   menampilkan karakter 219 sebagai representasi Segment.
//   karakter ditampilkan 2x berjajar dengan asusmsi bahwa
//   ukuran 1 grid setara 2 karakter bersebelahan.
// parameter: -
// kembalian: void

void Snake::show()
{
	text_color(10);
	for (auto& s : segments)
	{
		goto_xy(s.get_x() * 2, s.get_y());
		std::cout << char(219) << char(219);
	}
	text_color(7);
}