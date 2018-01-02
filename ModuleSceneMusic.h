#ifndef __MODULESCENEMUSIC_H__
#define __MODULESCENEMUSIC_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneMusic : public Module
{
public:
	ModuleSceneMusic(bool start_enabled = true);
	~ModuleSceneMusic();

	bool Start();
	update_status Update();
	//bool reDraw(int red, int green, int blue, int alpha, float lineWorldX, float lineWorldY, float lineWorldW, float lineScreenX, float lineScreenY, float lineScreenZ);
	bool CleanUp();

	//void reDraw(int red, int green, int blue, int alpha, float lineWorldX, float lineWorldY, float lineWorldW, float lineScreenX, float lineScreenY, float lineScreenW, int position);

public:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* magicalTexture = nullptr;
	SDL_Texture* breezeTexture = nullptr;
	SDL_Texture* waveTexture = nullptr;
	SDL_Texture* beatTexture = nullptr;

	SDL_Rect magicalRect;
	SDL_Rect breezeRect;
	SDL_Rect waveRect;
	SDL_Rect beatRect;

	unsigned int music2;
	int musicCount = 0;
	bool downOk = false;
	double secondsPassed;
	double secondsToQuit;
	bool finalize = false;
	long initTimer;

private:

};

#endif // __MODULESCENEMUSIC_H__