#ifndef __MODULESEGAINIT_H__
#define __MODULESEGAINIT_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSegaInit : public Module
{
public:
	ModuleSegaInit(bool start_enabled = true);
	~ModuleSegaInit();

	bool Start();
	//update_status Update();
	bool CleanUp();

	bool loadMedia();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect ground;
	SDL_Rect background;
	Animation flag;
	Animation girl;
	SDL_Rect ship;
	unsigned int music;
	int position = 0;
	bool downOk = false;
};

#endif // __MODULESEGAINIT_H__