/*
 * implementasi fungsi-fungsi bantu
 * menggunakan Win32 API
*/

#include <Windows.h>
#include <iostream>

// fungsi: goto_xy()
//   menempatkan kursor pada posisi x,y tertentu
// parameter:
//   - _x: posisi x kursor
//   - _y: posisi y kursor
// kembalian: void

void goto_xy(SHORT _x, SHORT _y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { _x, _y });
}

// fungsi: text_color()
//   mengganti warna text
// parameter:
//   - c: kode warna (0 - 15)
// kembalian: void

void text_color(SHORT _c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _c);
}

// fungsi: draw_box()
//   menggambar bentuk kotak menggunakan karakter ASCII
//   satuan menggunakan karakter konsol (bukan grid)
// parameter:
//   - _x: posisi x acuan
//   - _y: posisi y acuan
//   - _w: lebar dalam satuan karakter
//   - _h: tinggi dalam satuan karakter

void draw_box(SHORT _x, SHORT _y, SHORT _w, SHORT _h)
{
	goto_xy(_x, _y);
	std::cout << char(218);
	for (int i = 2; i <= _w - 1; ++i)
		std::cout << char(196);
	std::cout << char(191);

	goto_xy(_x, _y + _h - 1);
	std::cout << char(192);
	for (int i = 2; i <= _w - 1; ++i)
		std::cout << char(196);
	std::cout << char(217);

	for (int i = _y + 1; i < _y + _h - 1; ++i)
	{
		goto_xy(_x, i);
		std::cout << char(179);
		goto_xy(_x + _w - 1, i);
		std::cout << char(179);
	}
}
