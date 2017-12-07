#ifndef __ModuleCollision_H__
#define __ModuleCollision_H__

#include<list>
//#include "Module.h"

enum COLLIDER_TYPE
{
	COLLIDER_NONE = -1,
	COLLIDER_OBJECT,
	COLLIDER_ENEMY,
	COLLIDER_PLAYER,
	COLLIDER_MAX
};
//struct Collider
//{
//	SDL_Rect rect{ 0,0,0,0 };
//	bool enabled = false;
//
//	COLLIDER_TYPE type;
//	Module* callback;
//
//	Collider(SDL_Rect rectangle, COLLIDER_TYPE type, Module* callback = NULL) :
//		rect(rectangle),
//		type(type),
//		callback(callback),
//		enabled(true)
//	{}
//
//	//	Collider(SDL_Rect rectangle) : // expand this call if you need to
//	//		rect(rectangle)
//	//	{}
//
//	void SetPos(int x, int y)
//	{
//		rect.x = x;
//		rect.y = y;
//	}
//
//	bool CheckCollision(const SDL_Rect& r) const;
//};

class ModuleCollision //: public Module
{
public:

	ModuleCollision();
	~ModuleCollision();

	//update_status PreUpdate();
	//update_status Update();

	//bool CleanUp();

//	Collider* AddCollider(const SDL_Rect& rect, COLLIDER_TYPE type, Module* callback = NULL);
	//void DebugDraw();

private:

	//std::list<Collider*> colliders;
	bool debug = false;
	bool matrix[COLLIDER_MAX][COLLIDER_MAX];
};

#endif // __ModuleCollision_H__