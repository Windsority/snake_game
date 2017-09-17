#include "Snake.h"
#include <random>


Snake::Snake(const Location& loc)
{
	segment_[0].InitHead(loc);
}

void Snake::MoveBy(const Location &delta_loc)
{
	for (int i = length_ - 1; i > 0; --i)
	{
		segment_[i].Follow(segment_[i - 1]);
	}
	segment_[0].MoveBy(delta_loc);
}

void Snake::Draw(Board &board)
{
	for (int i = 0; i < length_; ++i)
	{
		segment_[i].Draw(board);
	}
}

Location& Snake::GetHeadLocation()
{
	return segment_[0].GetLocation();
}

Location Snake::GetNextHeadLocation(const Location& loc)
{
	Location head_loc = GetHeadLocation();
	head_loc.Add(loc);
	return head_loc;
}

void Snake::Grow()
{
	if (length_ < nMaxSegments)
	{
		segment_[length_].InitBody(GetHeadLocation());
		++length_;
	}
}

bool Snake::IsInTileExceptEnd(const Location &loc)
{
	for (int i = 0; i < length_ - 1; ++i)
	{
		if (loc == segment_[i].GetLocation()) return true;
	}
	return false;
}

bool Snake::IsInTile(const Location &loc)
{
	for (int i = 0; i < length_; ++i)
	{
		if (loc == segment_[i].GetLocation()) return true;
	}
	return false;
}

void Snake::Reset()
{
	length_ = 1;
}

int Snake::GetLength()
{
	return length_;
}

void Snake::Segment::Draw(Board &board)
{	
	board.DrawCell(loc_, color_);
}

void Snake::Segment::Follow(const Segment &next)
{
	loc_ = next.loc_;
}

void Snake::Segment::MoveBy(const Location &delta_loc)
{
	loc_.Add(delta_loc);
}

void Snake::Segment::InitHead(const Location &loc)
{
	loc_ = loc;
	color_ = HEAD_COLOR;
}

void Snake::Segment::InitBody(const Location &loc)
{
	std::random_device rd_device;
	std::mt19937 rand(rd_device());
	std::uniform_int_distribution<int> color_dist(0, 255);
	Color c = { (unsigned char)color_dist(rand), 
				(unsigned char)color_dist(rand), 
				(unsigned char)color_dist(rand) };
	loc_ = loc;
	color_ = c;
}

Location& Snake::Segment::GetLocation()
{
	return loc_;
}
