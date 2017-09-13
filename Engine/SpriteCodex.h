#pragma once

#include "Graphics.h"

class SpriteCodex
{
public:
	static void DrawGameOver( int x,int y,Graphics& gfx );
	static void DrawTitle( int x,int y,Graphics& gfx );
	static constexpr int GameOverWidth = 83, GameOverHeight = 63;
	static constexpr int GameStartWidth = 213, GameStartHeight = 160;
};