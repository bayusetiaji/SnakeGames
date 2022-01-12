#include "global.h"

const std::string title{ "SnakeD" };
const unsigned scr_width{ 490 };
const unsigned scr_height{ 545 };
const float grid_size{ 16.f };

const float world_pad_top{ 40.f };
const float world_pad_right{ 5.f };
const float world_pad_bottom{ 5.f };
const float world_pad_left{ 5.f }; 

const int num_grid_h{ static_cast<int>(scr_width - world_pad_left - world_pad_right) / static_cast<int>(grid_size) };
const int num_grid_v{ static_cast<int>(scr_height - world_pad_top - world_pad_bottom) / static_cast<int>(grid_size) };

const sf::Color snake_color{ 25, 174, 255 };
const sf::Color fruit_color{ 255, 65, 65 };