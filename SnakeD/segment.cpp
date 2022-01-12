#include "global.h"
#include "segment.h"

Segment::Segment() : _px{ 0 }, _py{ 0 }
{
	_x = 0;
	_y = 0;
	_init_shp();
}

Segment::Segment(const int x, const int y) : _px{ x }, _py{ y }
{
	_x = x;
	_y = y;
	_init_shp();
}

void Segment::save_prev_xy()
{
	_px = _x;
	_py = _y;
}

void Segment::follow(const Segment& sg)
{
	save_prev_xy();
	_x = sg._px;
	_y = sg._py;
}

void Segment::show(sf::RenderTarget& t)
{
	t.draw(_shp);
}

void Segment::grid_to_pix()
{
	_shp.setPosition(_x * grid_size + world_pad_left, _y * grid_size + world_pad_top);
}

void Segment::_init_shp()
{
	_shp.setSize({ grid_size, grid_size });
	_shp.setOrigin(grid_size / 2, grid_size / 2);
	grid_to_pix();
	_shp.setFillColor(snake_color);
}