#pragma once

#include "GameObject.h"
#include "algorithm"
#include "PlayScene.h"
#include "DefineAll.h"



class CBOOM : public CGameObject
{
	int type;
	bool isUsed = false;
	DWORD timing_start = 0;
public:

	CBOOM();
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();
	virtual void SetState(int state);
	void StartTiming()
	{
		if (timing_start == 0)
			timing_start = (DWORD)GetTickCount64();
	}
	void SetIsUsed(bool isUsedBool)
	{
		isUsed = isUsedBool;
	}
	bool GetIsUsed()
	{
		return isUsed;
	}
	int GetType()
	{
		return type;
	}
	void SetType(int typeInt)
	{
		type = typeInt;
	}

};