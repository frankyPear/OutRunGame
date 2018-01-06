#ifndef __MODULERENDER_H__
#define __MODULERENDER_H__

#include "Module.h"
#include "Globals.h"

struct SDL_Texture;
struct SDL_Renderer;
struct SDL_Rect;

class ModuleRender : public Module
{
public:
	ModuleRender();
	~ModuleRender();

	bool Init();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();

	bool Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section, float speed = 1.0f);

	bool ScaledBlit(SDL_Texture * texture, int x, int y, SDL_Rect * section, float speed, float scaledW, float scaledH);
	
	bool BlitObjects(SDL_Texture* texture, int x, int y, SDL_Rect* section, float speed, int scW, int scH, int elevate);

public:
	SDL_Renderer* renderer = nullptr;
	SDL_Rect camera;
	bool switchmap = false;
};

#endif // __MODULERENDER_H__