#pragma once

#include "global.h"
#include "snake.h"
#include "fruit.h"

#include <string>

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

namespace game
{
	
	extern int score;
	extern int hiscore;
	extern std::string str_score;
	extern std::string str_hiscore;
	extern bool st_gameover;
	extern bool st_gamerun;
	extern Direction dir;

	extern sf::RenderWindow window;
	extern sf::Font font;
	extern sf::Text txt_score;
	extern sf::Text txt_hiscore;
	extern sf::SoundBuffer buff_pick;
	extern sf::SoundBuffer buff_hit;
	extern sf::Sound sound;

	extern Snake snake;
	extern Fruit fruit;

	extern sf::RectangleShape rect_border;

	void init();
	void run();
	void end();

	void loop();
	void reset();
	void draw_score();
}