#pragma once
#include "Graphics.h"
#include "Location.h"
class Board
{
public:
	Board(Graphics&);
	void DrawCell(const Location&, Color);
	void DrawBorder();
	int GetGridWidth() const;
	int GetGridHeight() const;
	bool IsInsideBoard(const Location&) const;
private:
	static constexpr int bDimension = 20;
	static constexpr int bWidth = 20;
	static constexpr int bHeight = 20;
	static constexpr int xOffset = (Graphics::ScreenWidth - bWidth * bDimension) / 2;
	static constexpr int yOffset = (Graphics::ScreenHeight - bHeight * bDimension) / 2;
	static constexpr int bPadding = 5;
	Graphics& gfx_;
};

