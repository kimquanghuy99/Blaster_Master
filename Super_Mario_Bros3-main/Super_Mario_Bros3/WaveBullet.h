#pragma once
#include "GameObject.h"
#include "DefineAll.h"




class CWAVE_BULLET : public CGameObject
{
	int dir = 0;
	DWORD reset_start = 0;
	DWORD change_speed_start = 0;
	void StartReset() {if(reset_start == 0) reset_start = (DWORD)GetTickCount64(); }
	void StartSpeed() { if (change_speed_start == 0) change_speed_start = (DWORD)GetTickCount64(); }
	bool isUsed = false;
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();
	void CalcPotentialCollisions(vector<LPGAMEOBJECT>* coObjects, vector<LPCOLLISIONEVENT>& coEvents);

public:
	CWAVE_BULLET();
	void SetisUsed(bool value) { isUsed = value; }
	bool GetisUsed() { return isUsed; }
	virtual void SetState(int state);
};

