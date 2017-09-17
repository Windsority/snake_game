/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	board_(gfx),
	snek_({ 2, 2 }),
	rand_(std::random_device()()),
	goal_(rand_, board_, snek_)
{

}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!GameIsStart)
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN)) GameIsStart = true;
	}
	else if (!GameIsOver)
	{
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			if (prev_loc.y != 1 || snek_.GetLength() <= 2) delta_loc = { 0, -1 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			if (prev_loc.y != -1 || snek_.GetLength() <= 2) delta_loc = { 0, 1 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			if (prev_loc.x != 1 || snek_.GetLength() <= 2) delta_loc = { -1, 0 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			if (prev_loc.x != -1 || snek_.GetLength() <= 2) delta_loc = { 1, 0 };
		}

		Location next = snek_.GetNextHeadLocation(delta_loc);

		if (++time_counter_ >= GAME_PERIOD)
		{
			time_counter_ = 0;

			if (!board_.IsInsideBoard(next) || snek_.IsInTileExceptEnd(next))
			{
				GameIsOver = true;
			}
			else
			{
				bool eatting = next == goal_.GetLocation();

				if (eatting) snek_.Grow();
				snek_.MoveBy(delta_loc);
				prev_loc = delta_loc;
				if (eatting) goal_.Respawn(rand_, board_, snek_);
			}
		}
	}
	else if (wnd.kbd.KeyIsPressed('R'))
	{
		snek_.GetHeadLocation() = { 2, 2 };
		delta_loc = { 1, 0 };
		snek_.Reset();
		goal_.Respawn(rand_, board_, snek_);
		GameIsOver = false;
	}
}

void Game::ComposeFrame()
{
	const int center_x1 = (gfx.ScreenWidth - SpriteCodex::GameOverWidth) / 2;
	const int center_y1 = (gfx.ScreenHeight - SpriteCodex::GameOverHeight) / 2;
	const int center_x2 = (gfx.ScreenWidth - SpriteCodex::GameStartWidth) / 2;
	const int center_y2 = (gfx.ScreenHeight - SpriteCodex::GameStartHeight) / 2;

	if (!GameIsStart)
	{
		SpriteCodex::DrawTitle(center_x2, center_y2, gfx);
	}
	else 
	{
		board_.DrawBorder();
		snek_.Draw(board_);
		goal_.Draw(board_);
		if (GameIsOver)
		{
			SpriteCodex::DrawGameOver(center_x1, center_y1, gfx);
		}
	}
}
