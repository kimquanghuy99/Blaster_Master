#pragma once
#include "GameObject.h"
#define CSOPHIA_BULLET_SPEED 0.5f
#define CSOPHIA_BULLET_STATE_DIE_SPEED 0

#define CSOPHIA_BULLET_BBOX_WIDTH	7
#define CSOPHIA_BULLET_BBOX_HEIGHT 9

#define	CSOPHIA_BULLET_STATE_DIE	90
#define CSOPHIA_BULLET_STATE_FLYING 100

#define CSOPHIA_BULLET_ANI_FLYING_RIGHT 0
#define CSOPHIA_BULLET_ANI_FLYING_LEFT 1

#define CSOPHIA_BULLET_GRAVITY	0.0008f
#define CSOPHIA_BULLET_RESET_TIME 5000

#define STORING_LOCATION 5000


class CTANKBULLET : public CGameObject
{
	DWORD reset_start;
	void StartReset() { reset_start = (DWORD)GetTickCount64(); }
	bool isUsed = false;
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();
	void CalcPotentialCollisions(vector<LPGAMEOBJECT>* coObjects, vector<LPCOLLISIONEVENT>& coEvents);

public:
	CTANKBULLET();
	void SetisUsed(bool value) { isUsed = value; }
	bool GetisUsed() { return isUsed; }
	virtual void SetState(int state);
};

