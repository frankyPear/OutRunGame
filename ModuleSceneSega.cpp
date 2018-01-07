#include "Globals.h"
#include "Application.h"
#include "ModuleSceneSega.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFonts.h"
#include "ModuleAudio.h"
#include "ModuleWindow.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL.h"
#include "Point.h"


//#include "SDL/include/SDL2_imageFilter.c"
#include <SDL_mixer.h>
#include <ctime>


ModuleSceneSega::ModuleSceneSega(bool start_enabled) : Module(start_enabled)
{
// logo
logo.frames.push_back({ 8, 8, 208, 64 });
logo.frames.push_back({ 8, 81, 208, 64 });
logo.frames.push_back({ 8, 154, 208, 64 });
logo.frames.push_back({ 8, 227, 208, 64 });
logo.frames.push_back({ 8, 300, 208, 64 });
logo.frames.push_back({ 8, 373, 208, 64 });

logo.frames.push_back({ 224, 8, 208, 64 });
logo.frames.push_back({ 224, 81, 208, 64 });
logo.frames.push_back({ 224, 154, 208, 64 });
logo.frames.push_back({ 224, 227, 208, 64 });
logo.frames.push_back({ 224, 300, 208, 64 });
logo.frames.push_back({ 224, 373, 208, 64 });

logo.frames.push_back({ 440, 8, 208, 64 });
logo.frames.push_back({ 440, 81, 208, 64 });
logo.frames.push_back({ 440, 154, 208, 64 });
logo.frames.push_back({ 440, 227, 208, 64 });
logo.frames.push_back({ 440, 300, 208, 64 });
logo.frames.push_back({ 440, 373, 208, 64 });

logo.frames.push_back({ 656, 8, 208, 64 });
logo.frames.push_back({ 656, 81, 208, 64 });
logo.frames.push_back({ 656, 154, 208, 64 });

outrunLogo.frames.push_back({ 23 , 1, 352, 174 });
outrunLogo.frames.push_back({ 385, 1, 352, 174 });
outrunLogo.frames.push_back({ 748, 1, 352, 174 });

outrunLogo.frames.push_back({ 22 , 182, 352, 173 });
outrunLogo.frames.push_back({ 383, 184, 352, 173 });
outrunLogo.frames.push_back({ 747, 182, 352, 173 });
										
outrunLogo.frames.push_back({ 18 , 365, 352, 174 });
outrunLogo.frames.push_back({ 382, 365, 352, 174 });
outrunLogo.frames.push_back({ 746, 365, 352, 174 });

OutRunHeader.x = 0;
OutRunHeader.y = 0;
OutRunHeader.w = 1024;
OutRunHeader.h = 768;

outrunLogo.speed = 0.20f;
logo.speed = 0.25f;


}

ModuleSceneSega::~ModuleSceneSega()
{}

// Load assets
bool ModuleSceneSega::Start()
{
	LOG("Loading sega scene");

	graphics = App->textures->Load(SEGAPATH);
	IntroOutrun = App->textures->Load(INTROPATH);
	logoOutrun = App->textures->Load(LOGOPATH);
	//App->audio->PlayMusic(SOUNDBREEZEPATH, 1.0f);
	finalize = false;
	clock_t initT = clock();
	initTimer = initT;
	secondsToQuit = 3;
	return true;
}
// UnLoad assets
bool ModuleSceneSega::CleanUp()
{
	LOG("Unloading sega scene");
	App->textures->Unload(logoOutrun);
	App->textures->Unload(IntroOutrun);
	App->textures->Unload(graphics);
	
	

	return true;
}

// Update: draw background
update_status ModuleSceneSega::Update()
{

	if (!finalize) {
		App->renderer->Blit(graphics, (SCREEN_WIDTH / 2) - (208 / 2), (SCREEN_HEIGHT / 2) - (64 / 2), &(logo.GetCurrentFrame()), 0.40f);		
	}
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN && App->fade->isFading() == false) {
		App->fade->FadeToBlack((Module*)App->scene_music, this);
	}
	//logoSega//
	secondsPassed = (clock() - initTimer) / CLOCKS_PER_SEC;
	if (secondsPassed >= secondsToQuit ){
		finalize = true;
		/*Descomentar*/
		App->renderer->Blit(IntroOutrun, 0, 0, &OutRunHeader, 0.25f);
		if ((int)secondsPassed % 3 == 0)App->fonts->PrintCharacter(App->fonts->greenFonts, 325, 500, "PRESS SPACE BUTTON");
		App->fonts->PrintCharacter(App->fonts->pinkFonts, 100, 700, "CREDIT 0");
		App->renderer->Blit(logoOutrun, (SCREEN_WIDTH / 2) - (208 / 2) - 75, (SCREEN_HEIGHT / 2) - (64 / 2) - 100, &(outrunLogo.GetCurrentFrame()), 0.20f);
		App->fonts->PrintCharacter(App->fonts->lightgreenFonts, 800, 700, "Ç1986 1991");
		App->fonts->PrintCharacter(App->fonts->lightgreenFonts, 870, 720, "SEGA");
		return UPDATE_CONTINUE;
	}
	return UPDATE_CONTINUE;
}
