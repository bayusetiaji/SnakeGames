/*
 * implementasi 'game manager'
*/

#include "game.h"

// inisialisasi:
Direction dir{ Direction::Idle };
int score{ 0 };
int hiscore{ score };
bool st_game_over{ false };
bool st_game_run{ true };

Snake snake{ 20, 20, 5 };
Fruit fruit{ 20, 15 };

// fungsi: chdir()
//   men-set arah gerakan berdasar kode karakter.
// parameter:
//   - c: kode karakter
// kembalian: void

void chdir(const int c)
{
	if (c == 72)				// tombol panah atas
		dir = Direction::Up;
	else if (c == 77)			// tombol panah kanan
		dir = Direction::Right;	
	else if (c == 80)			// tombol panah bawah
		dir = Direction::Down;
	else if (c == 75)			// tombol panah kiri
		dir = Direction::Left;
	else if (c == 32)			// tombol spasi
		dir = Direction::Idle;

}

// fungsi: draw_score()
//   menampilkan perolehan skor dan skor tertinggi
//   di atas layar.
// parameter: -
// kembalian: void

void draw_score()
{
	text_color(14);
	goto_xy(2, 1);
	std::cout << "score: " << score;
	goto_xy(67, 1);
	std::cout << "hi-score: " << hiscore;
	goto_xy(0, 0);
	text_color(7);
}

// fungsi: draw_gover()
//   menampilkan layar Game Over
// parameter: -
// kembalian: void

void draw_gover()
{
	std::system("cls");
	draw_box(5, 10, 70, 15);
	goto_xy(33, 16);
	text_color(12);
	std::cout << "G A M E O V E R";
	goto_xy(35, 18);
	text_color(14);
	std::cout << "score: " << score;
	goto_xy(32, 19);
	std::cout << "hi-score: " << hiscore;

	goto_xy(26, 23);
	text_color(7);
	std::cout << "Escape: Exit | Others: Replay";
	goto_xy(26, 24);
	text_color(7);

	if (_getch() == 27)
		st_game_run = false;
	else
		game_reset();
}

// fungsi: game_start()
//   menampilkan layar splash sebelum game dimulai
// parameter: -
// kembalian: void

void game_start()
{
	SetConsoleTitle(L"SnakeC");
	std::system("cls");
	draw_box(5, 10, 70, 15);
	goto_xy(36, 13);
	std::cout << "SNAKE-C";
	goto_xy(24, 15);
	std::cout << "Console-Based Classic Snake Game";
	goto_xy(28, 16);
	std::cout << "bayusetiaji@amikom.ac.id";
	goto_xy(25, 20);
	std::system("pause");
}

// fungsi: game_reset()
//   me-reset state game
// parameter: -
// kembalian: void

void game_reset()
{
	st_game_over = false;
	dir = Direction::Idle;
	score = 0;

	snake.reset(20, 20);
	fruit.reset();
	fruit.set_x(20);
	fruit.set_y(15);
}

// fungsi: game_run()
//   sebagai main-loop dari game. semua objek game di-update
//   state-nya dan ditampilkan di layar tiap siklus.
//   jika state game adalah game over maka akan muncul layar 
//   'Game Over' yang berisi pilihan apakah akan memainkan
//   ulang atau keluar.
// parameter: -
// kembalian: void

void game_run() {
	// main-loop:
	while (st_game_run)
	{
		// gameplay:
		while (!st_game_over)
		{
			std::system("cls");

			// event: key_pressed
			if (_kbhit())
				chdir(_getch());

			fruit.live();
			fruit.show();

			if (snake.eat(fruit))
			{
				Beep(900, 200);
				score++;				
				if (score > hiscore)
					hiscore = score;

				fruit.reset();
			}

			if (snake.hit()) {
				Beep(200, 500);
				st_game_over = true;
			}

			snake.move(dir);
			snake.show();

			draw_score();

			Sleep(delay);
		}

		draw_gover();
	}
}

// fungsi: game_end()
//   menampilkan layar Game End yang berisi
//   animasi tulisan.
// parameter: -
// kembalian: void

void game_end()
{
	std::string msg{ "See You later..." };
	
	std::system("cls");
	draw_box(5, 10, 70, 15);
	
	goto_xy(32, 16);
	for (size_t i = 0; i < msg.length(); ++i)
	{
		text_color(8 + i % 7);
		std::cout << msg[i];
		Sleep(250);
	}

	text_color(7);
}