#include "Board.h"
#include <cassert>



Board::Board(Graphics& gfx)
	:
	gfx_(gfx)
{
}

void Board::DrawCell(const Location& loc, Color color)
{
	int loc_x = loc.x, loc_y = loc.y;
	assert(loc_x >= 0 || loc_y >= 0);
	assert(loc_x < bWidth || loc_y < bHeight);
	gfx_.DrawRectDim( loc_x * bDimension + xOffset, loc_y * bDimension + yOffset, 
					  bDimension, bDimension, color	);
}

void Board::DrawBorder()
{
	gfx_.DrawRect(xOffset - bPadding, yOffset - bPadding, 
		xOffset + bPadding + bWidth * bDimension, yOffset, Colors::Gray);
	gfx_.DrawRect(xOffset - bPadding, yOffset + bHeight * bDimension,
		xOffset + bPadding + bWidth * bDimension, 
		yOffset + bHeight * bDimension + bPadding, Colors::Gray);
	gfx_.DrawRect(xOffset - bPadding, yOffset, xOffset, 
		yOffset + bHeight * bDimension, Colors::Gray);
	gfx_.DrawRect(xOffset + bWidth * bDimension, yOffset, xOffset + bWidth * bDimension + bPadding, 
		yOffset + bHeight * bDimension + bPadding, Colors::Gray);
}

int Board::GetGridWidth() const
{
	return bWidth;
}

int Board::GetGridHeight() const
{
	return bHeight;
}

bool Board::IsInsideBoard(const Location &loc) const
{
	return loc.x < bWidth && 
		   loc.x >= 0 &&
		   loc.y < bHeight && 
		   loc.y >= 0;
}
