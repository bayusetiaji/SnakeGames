/*
 * interface untuk 'game manager' yang berisi 
 * data dan fungsi-fungsi utama
*/

#pragma once

#include <Windows.h>
#include <conio.h>
#include <iostream>

#include "snake.h"
#include "fruit.h"
#include "box.h"

extern Direction dir;		// nilai arah

extern int score;			// nilai score
extern int hiscore;			// niai hi-score
extern bool st_game_over;	// status game over?
extern bool st_game_run;	// status game run?

void chdir(const int);
void draw_score();
void draw_gover();
void game_start();
void game_reset();
void game_run();
void game_end();