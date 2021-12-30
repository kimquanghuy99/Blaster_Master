#pragma once
#include "GameObject.h"
#include "DefineAll.h"


class CNoCollisionObject : public CGameObject
{
	bool isRender;
	int type;
public:
	CNoCollisionObject();
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
};
