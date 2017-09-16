#include "Board.h"
#include <cassert>



Board::Board(Graphics& gfx)
	:
	gfx_(gfx)
{
}

void Board::DrawCell(Location& loc, Color color)
{
	int loc_x = loc.first, loc_y = loc.second;
	assert(loc_x >= 0 || loc_y >= 0);
	assert(loc_x < bWidth || loc_y < bHeight);
	gfx_.DrawRectDim(loc_x * bDimension, loc_y * bDimension, bDimension, bDimension, color);
}

int Board::GetGridWidth() const
{
	return bWidth;
}

int Board::GetGridHeight() const
{
	return bHeight;
}
