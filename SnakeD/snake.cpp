#include "global.h"
#include "snake.h"

#include <algorithm>

Snake::Snake() : _num{ 5 }
{
	reset(0, 0);
}

Snake::Snake(const int x, const int y, const int n) : _num{ n }
{
	reset(x, y);
}

bool Snake::eat(Fruit& f)
{
	return _segments[0].get_x() == f.get_x() && _segments[0].get_y() == f.get_y();
}

bool Snake::hit()
{
	auto& h = _segments[0];

	auto it = find_if(std::begin(_segments) + 1, std::end(_segments), [&](Segment& s) {
		return h.get_x() == s.get_x() && h.get_y() == s.get_y();
	});

	return  h.get_x() <= 0 || h.get_x() >= num_grid_h ||
	        h.get_y() <= 0 || h.get_y() >= num_grid_v ||
	        it != std::end(_segments);
}

void Snake::grow()
{
	auto& l = _segments[_segments.size() - 1];
	_segments.push_back(Segment{l.get_x(), l.get_y()});
}

void Snake::reset(const int x, const int y)
{
	_segments.clear();
	_dir = Direction::Idle;
	_t_elapsed = sf::Time::Zero;

	for (int i = 0; i < _num; ++i)
		_segments.push_back(Segment{ x, y + i });
}

void Snake::move(Direction& dir)
{
	_dir = dir;
}

void Snake::update(const int elps)
{
	sf::Time t_delta = _clock.restart();
	_t_elapsed += t_delta;
	
	if (_t_elapsed >= sf::milliseconds(elps))
	{
		auto& h = _segments[0];
		h.save_prev_xy();

		if (_dir == Direction::Up) 
			h.set_y(h.get_y() - 1);
		else if (_dir == Direction::Right)
			h.set_x(h.get_x() + 1);
		else if (_dir == Direction::Down)
			h.set_y(h.get_y() + 1);
		else if (_dir == Direction::Left)
			h.set_x(h.get_x() - 1);

		h.grid_to_pix();

		if (_dir != Direction::Idle)
		{
			for (size_t i = 1; i < _segments.size(); ++i)
			{
				_segments[i].follow(_segments[i - 1]);
				_segments[i].grid_to_pix();
			}
		}

		_t_elapsed = sf::Time::Zero;
	}
}

void Snake::show(sf::RenderTarget& t)
{
	for (auto& s : _segments)
		s.show(t);
}