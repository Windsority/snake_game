#pragma once
#include "Board.h"
#include "Snake.h"
#include <random>

class Goal
{
public:
	Goal(std::mt19937&, const Board&, Snake&);
	void Respawn(std::mt19937&, const Board&, Snake&);
	void Draw(Board&);
	Location& GetLocation();
private:
	static constexpr Color COLOR = Colors::Red;
	Location loc_;
};

