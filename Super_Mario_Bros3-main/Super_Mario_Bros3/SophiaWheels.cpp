#include "SophiaWheels.h"
#include <algorithm>
#include "PlayScene.h"


SOPHIAWHEEL::SOPHIAWHEEL(int part)
{
	this->part = part;
}

void SOPHIAWHEEL::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
}

void SOPHIAWHEEL::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	
	CGameObject::Update(dt, coObjects);

	CSOPHIA* SOPHIA = ((CPlayScene*)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	switch(part)
	{
	case SOPHIAWHEEL_LEFT_WHEEL:
			x = SOPHIA->x + SOPHIAWHEEL_WHEEL_DISTANT_X_1;
			if (SOPHIA->GetisAimingUp())
			{
				if (nx > 0)
				{
					x = x + 4;
				}
			}
			break;
	case SOPHIAWHEEL_RIGHT_WHEEL:
			x = SOPHIA->x + SOPHIAWHEEL_WHEEL_DISTANT_X_2;
			if (SOPHIA->GetisAimingUp())
			{
				if (nx > 0)
				{
					x = x - 2;
				}
			}
			break;
			break;
	}

	y = SOPHIA->y + SOPHIAWHEEL_WHEEL_DISTANT_Y;

	float Py, Px;
	SOPHIA->GetSpeed(Px, Py);

	if (SOPHIA->GetIsJumping() && Py > 0)
	{
		y = y + 6;
	}
	
		x += dx;
		y += dy;

}


void SOPHIAWHEEL::Render()
{
	CSOPHIA* SOPHIA = ((CPlayScene*)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	int ani = 0;

	if (SOPHIA->GetState() == SOPHIA_STATE_WALKING_RIGHT)
	{
		switch (part)
		{
		case SOPHIAWHEEL_RIGHT_WHEEL:
			ani = WHEELING_ANI_RIGHT;
			break;
		case SOPHIAWHEEL_LEFT_WHEEL:
			ani = WHEELING_ANI_RIGHT;
			break;
		}
	}

	else if (SOPHIA->GetState() == SOPHIA_STATE_WALKING_LEFT)
	{
		switch (part)
		{
		case SOPHIAWHEEL_RIGHT_WHEEL:
			ani = WHEELING_ANI_LEFT;
			break;
		case SOPHIAWHEEL_LEFT_WHEEL:
			ani = WHEELING_ANI_LEFT;
			break;
		}
	}

	else if(SOPHIA->vx == 0)
	{
		if (part != SOPHIAWHEEL_TURRET)
			ani = WHEELING_ANI_IDLE;
		else
			ani = pre_ani;
	}
	int alpha = 255;
	if (SOPHIA->getUntouchable()) alpha = 128;

	animation_set->at(ani)->Render(x, y, alpha);

	//RenderBoundingBox();
}

void SOPHIAWHEEL::SetState(int state)
{
	CGameObject::SetState(state);
	//switch (state)
	//{
	//case TANKWHEEL_STATE_DIE:
	//	vx = FIRE_BALL_STATE_DIE_VX;
	//	vy = FIRE_BALLSTATE_DIE_VY;
	//	break;

	//}

}
