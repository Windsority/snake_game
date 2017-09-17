#pragma once
#include "Colors.h"
class ColorManage
{
public:
	Color GetColor();
private:
	struct State {
		int r_change_, g_change_, b_change_;
		bool operator==(const State& rhs) const
		{
			return r_change_ == rhs.r_change_ &&
				   g_change_ == rhs.g_change_ &&
				   b_change_ == rhs.b_change_;
		}
	};
	unsigned char r = 255, g = 0, b = 0;
	State state = { 0, 1, 0 };
	static constexpr State STATES[] = {
		{0, 1, 0}, {-1, 0, 0}, {0, -1, 1}, {1, 0, -1}
	};
};

