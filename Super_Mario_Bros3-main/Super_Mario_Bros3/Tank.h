#pragma once
#pragma once
#include "GameObject.h"

#define TANK_STATE_DIE 0
#define TANK_BBOX_WIDTH 10
#define TANK_BBOX_HEIGHT 10

#define TANK_WHEEL_DISTANT_X 9
#define TANK_WHEEL_DISTANT_Y 0
#define TANK_TURRET_DISTANT_X 9
#define TANK_TURRET_DISTANT_Y 10

#define TANK_LEFT_WHEEL 0
#define TANK_RIGHT_WHEEL 1
#define TANK_TURRET 2

#define WHEELING_ANI_RIGHT 0
#define WHEELING_ANI_LEFT 1
#define WHEELING_ANI_IDLE 2

#define TURRET_ANI_IDLE_LEFT 1
#define TURRET_ANI_IDLE_RIGHT 0






class Tank : public CGameObject
{
	int part = 0;
	int pre_ani = 0;
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();
	void CalcPotentialCollisions(vector<LPGAMEOBJECT>* coObjects, vector<LPCOLLISIONEVENT>& coEvents);

public:
	float upBoudary;
	Tank(int part);
	virtual void SetState(int state);
};

