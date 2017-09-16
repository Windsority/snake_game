#pragma once
#include "Graphics.h"
#include <functional>
using Location = std::pair<int, int>;
class Board
{
public:
	Board(Graphics&);
	void DrawCell(Location&, Color);
	int GetGridWidth() const;
	int GetGridHeight() const;
private:
	static constexpr int bDimension = 20;
	static constexpr int bWidth = 10;
	static constexpr int bHeight = 10;
	Graphics& gfx_;
};

