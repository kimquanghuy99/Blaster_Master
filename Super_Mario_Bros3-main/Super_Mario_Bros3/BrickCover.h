#pragma once
#include "GameObject.h"
#include "DefineAll.h"



class CBREAKABLE_BRICK : public CGameObject
{
public:
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
};