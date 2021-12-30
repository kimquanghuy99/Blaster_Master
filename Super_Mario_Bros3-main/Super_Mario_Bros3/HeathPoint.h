#pragma once
#include "GameObject.h"
#include "DefineAll.h"


class CSTATBAR : public CGameObject
{
	bool isRender;
	int type;
public:
	CSTATBAR(int type);
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
};
