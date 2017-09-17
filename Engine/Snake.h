#pragma once
#include "Board.h"
#include "Location.h"
#include "Colors.h"
#include "ColorManage.h"
class Snake
{
public:
	Snake(const Location&);
	void MoveBy(const Location&);
	void Draw(Board&);
	Location& GetHeadLocation();
	Location GetNextHeadLocation(const Location&);
	void Grow();
	bool IsInTileExceptEnd(const Location&);
	bool IsInTile(const Location&);
	void Reset();
	int GetLength();
private:
	class Segment
	{
	public:
		void Draw(Board&, Color);
		void Follow(const Segment&);
		void MoveBy(const Location&);
		void InitHead(const Location&);
		void InitBody(const Location&);
		Location& GetLocation();
	private:
		Location loc_;
	};

	static constexpr Color HEAD_COLOR = Colors::Yellow;
	static constexpr Color BODY_COLOR = Colors::Green;

	ColorManage color_geter;
	static constexpr int nMaxSegments = 400;
	int length_ = 1;
	Segment segment_[nMaxSegments];
};

