#ifndef __MODULEPLAYER_H__
#define __MODULEPLAYER_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "Point.h"

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer(bool start_enabled = true);
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	float playerX = 0;
	float playerY = 0;
	double speed;
	Animation idle;
	Animation backward;
//PLAYER ANIMATIONS
	Animation playerAnimation;
	Animation manAnimation;
	Animation womanAnimation;
	Animation playerAnimationLeft1;
	Animation playerAnimationLeft2;
	Animation playerAnimationRight1;
	Animation playerAnimationRight2;
//CAR1 - Animations
	Animation car1Left;
	Animation car1Left1;
	Animation car1Left2;
	Animation car1Right;
	Animation car1Right1;
	Animation car1Right2;
//CAR2 - Animations
	Animation car2Left;
	Animation car2Left1;
	Animation car2Left2;
	Animation car2Right;
	Animation car2Right1;
	Animation car2Right2;
//TRUCK - Animations
	Animation truckLeft;
	Animation truckLeft1;
	Animation truckLeft2;
	Animation truckRight;
	Animation truckRight1;
	Animation truckRight2;

	int animations;

	//Animation ryu;
	iPoint position;
	bool directionleft = false; //0 stop //1 left // 2 right
};

#endif // __MODULEPLAYER_H__