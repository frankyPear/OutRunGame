#ifndef __MODULESCENESTART_H__
#define __MODULESCENESTART_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneStart : public Module
{
public:
	ModuleSceneStart(bool start_enabled = true);
	~ModuleSceneStart();

	bool Start();
	update_status Update();
	//bool reDraw(int red, int green, int blue, int alpha, float lineWorldX, float lineWorldY, float lineWorldW, float lineScreenX, float lineScreenY, float lineScreenZ);
	bool CleanUp();

	//void reDraw(int red, int green, int blue, int alpha, float lineWorldX, float lineWorldY, float lineWorldW, float lineScreenX, float lineScreenY, float lineScreenW, int position);

public:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* road = nullptr;
	SDL_Rect ground;
	SDL_Rect background;
	Animation playerAnimation;
	Animation logoOutrun;
	unsigned int music2;
	int position = 0;
	bool downOk = false;
	double secondsPassed;
	double secondsToQuit;
	bool finalize = false;
	long initTimer;
	//std::vector<Line> lines;
	//clock_t initTime = clock();
private:
	//clock_t initTime;

};

#endif // __MODULESCENESEGA_H__