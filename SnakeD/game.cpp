#include "global.h"
#include "game.h"

#include <string>
#include <iostream>

namespace game
{
	int score{ 0 };
	int hiscore{ score };
	bool st_gameover{ false };
	bool st_gamerun{ false };
	Direction dir{ Direction::Idle };

	sf::RenderWindow window;
	sf::RectangleShape rect_border;
	sf::Font font;
	sf::Text txt_score;
	sf::Text txt_hiscore;
	sf::SoundBuffer buff_pick;
	sf::SoundBuffer buff_hit;
	sf::Sound sound;

	Snake snake;
	Fruit fruit;

	void init()
	{
		window.create(sf::VideoMode{ scr_width, scr_height }, "Snaked", sf::Style::Close);

		rect_border.setPosition(world_pad_left, world_pad_top);
		rect_border.setSize({scr_width - world_pad_left - world_pad_right, scr_height - world_pad_top - world_pad_bottom});
		rect_border.setFillColor(sf::Color(0));
		rect_border.setOutlineThickness(1);
		rect_border.setOutlineColor(snake_color);

		font.loadFromFile("Exo-DemiBold.otf");

		txt_score.setFont(font);
		txt_score.setCharacterSize(15);
		txt_score.setString("Score: 0");
		txt_score.setFillColor(sf::Color{204, 255, 66});
		txt_score.setPosition(10.f, grid_size - 4.f);

		txt_hiscore.setFont(font);
		txt_hiscore.setCharacterSize(15);
		txt_hiscore.setString("Hi-Score: 0");
		txt_hiscore.setFillColor(sf::Color{ 204, 255, 66 });
		txt_hiscore.setPosition(375.f, grid_size - 4.f);

		buff_pick.loadFromFile("pick.wav");
		buff_hit.loadFromFile("hit.wav");

		snake.reset(15, 15);
		fruit._init_shp();
		fruit.locate(15, 12);

		st_gamerun = true;
	}

	void run()
	{
		while (window.isOpen())
		{
			sf::Event e;
			while (window.pollEvent(e))
			{
				if (e.type == sf::Event::Closed) window.close();
				if (e.type == sf::Event::KeyPressed)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) dir = Direction::Up;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) dir = Direction::Right;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) dir = Direction::Down;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) dir = Direction::Left;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) dir = Direction::Idle;
				}
			}

			window.clear();
			window.draw(rect_border);
						
			snake.move(dir);
			snake.update(200);
			snake.show(window);

			fruit.update(200);
			fruit.show(window);

			if (snake.hit())
			{
				reset();
				sound.setBuffer(buff_hit);
				sound.play();
			}

			if (snake.eat(fruit))
			{
				snake.grow();
				fruit.reset();

				score++;
				if (score > hiscore)
					hiscore = score;

				sound.setBuffer(buff_pick);
				sound.play();
			}

			draw_score();

			window.display();
		}
	}

	void end()
	{

	}

	void loop()
	{
		
	}

	void reset()
	{
		snake.reset(15, 15);
		fruit.reset();
		fruit.locate(15, 12);
		score = 0;
		dir = Direction::Idle;
	}

	void draw_score()
	{
		auto str_score = std::string{ "Score : " }.append(std::to_string(score));
		auto str_hiscore = std::string{ "Hi-Score: " }.append(std::to_string(hiscore));

		txt_score.setString(str_score);
		txt_hiscore.setString(str_hiscore);

		window.draw(txt_score);
		window.draw(txt_hiscore);
	}
}