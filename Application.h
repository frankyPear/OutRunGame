#ifndef __APPLICATION_CPP__
#define __APPLICATION_CPP__

#include<list>
#include "Globals.h"
#include "Module.h"

class ModuleRender;
class ModuleWindow;
class ModuleTextures;
class ModuleInput;
class ModuleAudio;
class ModuleFadeToBlack;
class ModulePlayer;
class ModuleFonts;
class ModuleSceneSega;
class ModuleCollision;
class ModuleSceneStage;
class ModuleSceneMusic;
class ModuleTimer;
//class ModuleSegaInit;

class Application
{
public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

	void RerunTimer();

public:
	ModuleRender* renderer;
	ModuleWindow* window;
	ModuleTextures* textures;
	ModuleInput* input;
	ModuleAudio* audio;
	ModuleFonts* fonts;
	ModuleFadeToBlack* fade;
	ModulePlayer* player;
	ModuleSceneSega* scene_sega;
	ModuleSceneStage* scene_stage;
	ModuleSceneMusic* scene_music;
	ModuleCollision* colliders;
	ModuleTimer* Rtimer;
	bool switchmap = false;
private:

	std::list<Module*> modules;

};

extern Application* App;

#endif // __APPLICATION_CPP__