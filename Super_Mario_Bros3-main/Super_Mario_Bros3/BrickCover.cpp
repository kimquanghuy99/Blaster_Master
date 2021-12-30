#include "BrickCover.h"

void CBREAKABLE_BRICK::Render()
{
	//if (state != STATE_DIE)
	{
		animation_set->at(0)->Render(x, y);
		//RenderBoundingBox();
	}
}

void CBREAKABLE_BRICK::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	if (state != STATE_DIE)
	{
		l = x;
		t = y;
		r = x + COVER_BRICK_BBOX_WIDTH;
		b = y + COVER_BRICK_BBOX_HEIGHT;
	}
}