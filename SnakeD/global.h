#pragma once

#include <SFML\Graphics.hpp>
#include <string>

extern const std::string title;
extern const unsigned scr_width;
extern const unsigned scr_height;
extern const float grid_size;

extern const float world_pad_top;
extern const float world_pad_right;
extern const float world_pad_bottom;
extern const float world_pad_left;

extern const int num_grid_h;
extern const int num_grid_v;

extern const sf::Color snake_color;
extern const sf::Color fruit_color;



enum Direction{Idle, Up, Right, Down, Left};