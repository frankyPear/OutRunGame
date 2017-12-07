#include "ModuleCollision.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"


ModuleCollision::ModuleCollision()
{
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_MAX] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_OBJECT] = true;

	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_MAX] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_OBJECT] = false;

	matrix[COLLIDER_OBJECT][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_OBJECT][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_OBJECT][COLLIDER_MAX] = false;
	matrix[COLLIDER_OBJECT][COLLIDER_OBJECT] = false;

	matrix[COLLIDER_MAX][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_MAX][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_MAX][COLLIDER_MAX] = false;
	matrix[COLLIDER_MAX][COLLIDER_OBJECT] = false;

}

ModuleCollision::~ModuleCollision()
{
}

//update_status ModuleCollision::PreUpdate()
//{
//	return update_status();
//}
//
//update_status ModuleCollision::Update()
//{
//	return update_status();
//}

//bool ModuleCollision::CleanUp()
//{
//	return false;
//}
//
//Collider * ModuleCollision::AddCollider(const SDL_Rect & rect, COLLIDER_TYPE type, Module * callback)
//{
//	return nullptr;
//}

//bool Collider::CheckCollision(const SDL_Rect & r) const
//{
//	return false;
//}

//bool Collider::CheckCollision(const SDL_Rect & r) const
//{
//	return false;
//}
