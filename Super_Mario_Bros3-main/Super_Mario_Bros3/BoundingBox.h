#pragma once
#include "GameObject.h"
#define BoundingBoxObject_TYPE_NORMAL	1
#define BoundingBoxObject_TYPE_NUMBER_THREE	2
#define BoundingBoxObject_TYPE_BUSH_INTRO_SCENE	3
class CNoCollisionObject : public CGameObject
{
	bool isRender;
	int type;
public:
	CNoCollisionObject();
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
};
