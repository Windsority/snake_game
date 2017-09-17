#include "ColorManage.h"


Color ColorManage::GetColor()
{
	if (state == STATES[0])
	{
		if (g == 255) state = STATES[1];
		else ++g;
	}
	else if (state == STATES[1])
	{
		if (r == 0) state = STATES[2];
		else --r;
	}
	else if (state == STATES[2])
	{
		if (g == 0 && b == 255)
		{
			state = STATES[3];
		}
		else
		{
			if (g > 0) --g;
			if (b < 255) ++b;
		}
	}
	else if (state == STATES[3])
	{
		if (r == 255 && b == 0)
		{
			state = STATES[0];
		}
		else
		{
			if (r < 255) ++r;
			if (b > 0) --b;
		}
	}
	return { r, g, b };
}
