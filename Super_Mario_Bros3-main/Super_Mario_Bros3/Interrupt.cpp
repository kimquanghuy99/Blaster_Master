#include "Interrupt.h"
CINTERRUPT::CINTERRUPT()
{
	SetState(CINTERRUPT_STATE_IDLE);
}

void CINTERRUPT::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + CINTERRUPT_BBOX_WIDTH;

	if (state == CINTERRUPT_STATE_DIE)
		bottom = y + CINTERRUPT_BBOX_HEIGHT_DIE;
	else
		bottom = y + CINTERRUPT_BBOX_HEIGHT;
}

void CINTERRUPT::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);
	if (GetTickCount() - untouchable_start > MARIO_UNTOUCHABLE_TIME)
	{
		untouchable_start = 0;
		untouchable = 0;
	}
	//
	// TO-DO: make sure Goomba can interact with the world and to each of them too!
	// 

	//x += dx;
	//y += dy;
}

void CINTERRUPT::Render()
{

	int ani = CINTERRUPT_ANI;
	if (state == CINTERRUPT_STATE_DIE) {
		ani = CINTERRUPT_ANI_DIE;
	}
	animation_set->at(ani)->Render(x, y);

	//RenderBoundingBox();
}

void CINTERRUPT::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case CINTERRUPT_STATE_IDLE:
		//vx = CINTERRUPT_STATE_IDLE;
		break;
	case CINTERRUPT_STATE_DIE:
		vx = 0;
		vy = 0;
		break;
	}
}
