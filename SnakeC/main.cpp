/*
 * Game Snake-C
 * bayusetiaji@amikom.ac.id
 *
 * Game Snake berbasis konsol untuk Win32.
 * Game dapat berjalan optimal pada konsol dengan
 * seting:
 * - ukuran layout konsol = 80x40
 * - font dengan rasio (width:height) = 1:2
 * - ukuran buffer = 80;
 *
*/

#include "game.h"

int main()
{
	game_start();
	game_run();
	game_end();
	
	return 0;
}