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
	segment_[0].Draw(board, HEAD_COLOR);
	for (int i = 1; i < length_; ++i)
	{
		segment_[i].Draw(board, color_geter.GetColor());
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

void Snake::Segment::Draw(Board &board, Color color)
{
	board.DrawCell(loc_, color);
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
}

void Snake::Segment::InitBody(const Location &loc)
{
	loc_ = loc;
}

Location& Snake::Segment::GetLocation()
{
	return loc_;
}
