#include "Goal.h"


Goal::Goal(std::mt19937 &rand, const Board &board, Snake &snek)
{
	Respawn(rand, board, snek);
}

void Goal::Respawn(std::mt19937 &rand, const Board &board, Snake &snek)
{
	std::uniform_int_distribution<int> board_width_dist(0, board.GetGridWidth() - 1);
	std::uniform_int_distribution<int> board_height_dist(0, board.GetGridHeight() - 1);

	Location new_loc;
	do {
		new_loc.x = board_width_dist(rand);
		new_loc.y = board_height_dist(rand);
	} while (snek.IsInTile(new_loc));

	loc_ = new_loc;
}

void Goal::Draw(Board &board)
{
	board.DrawCell(loc_, COLOR);
}

Location& Goal::GetLocation()
{
	return loc_;
}
