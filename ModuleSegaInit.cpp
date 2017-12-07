#include "Application.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleSceneKen.h"
#include "ModuleSceneHonda.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSegaInit.h"
#include "SDL/include/SDL.h"
#include <SDL_mixer.h>

ModuleSegaInit::ModuleSegaInit(bool start_enabled) : Module(start_enabled)
{
	//// ground
	//ground.x = 8;
	//ground.y = 391;
	//ground.w = 896;
	//ground.h = 72;
	//
	//// TODO 2 : setup the foreground (red ship) with
	//// coordinates x,y,w,h from ken_stage.png
	//ship.x = 7;
	//ship.y = 24;
	//ship.w = 522;
	//ship.h = 205;
	//
	//
	////App->renderer->Blit(graphics, 0, 0, &ship, 20.0f);
	//// Background / sky
	//background.x = 72;
	//background.y = 208;
	//background.w = 820;
	//background.h = 176;
	//
	//// flag animation
	//flag.frames.push_back({ 848, 208, 40, 40 });
	//flag.frames.push_back({ 848, 256, 40, 40 });
	//flag.frames.push_back({ 848, 304, 40, 40 });
	////flag.speed = 0.08f;
	//flag.speed = 0.48f;
	//// TODO 4: Setup Girl Animation from coordinates from ken_stage.png
	//// flag animation
	//girl.frames.push_back({ 624, 16, 32, 55 });
	//girl.frames.push_back({ 624, 80, 32, 55 });
	//girl.frames.push_back({ 624, 144, 32, 55 });
	//girl.speed = 0.15f;
}

ModuleSegaInit::~ModuleSegaInit()
{
}

bool ModuleSegaInit::Start()
{
	LOG("Loading Sega Init");
	graphics = App->textures->Load("SEGA.png");
	
	int result = loadMedia();
	//graphics = App->textures->Load("ken_stage.png");
	//
	//// TODO 7: Enable the player module
	//App->player->Enable();
	//// TODO 0: trigger background music
	//music = App->audio->LoadFx("ken.ogg");
	//App->audio->PlayFx(music, 1);

	return true;
}

//update_status ModuleSegaInit::Update()
//{
//	//return update_status();
//}
bool ModuleSegaInit::CleanUp()
{
	return false;
}
bool ModuleSegaInit::loadMedia() {
	bool success = true;

}