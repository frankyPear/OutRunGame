#include "Globals.h"
#include "Application.h"
#include "ModuleSceneMusic.h"
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


ModuleSceneMusic::ModuleSceneMusic(bool start_enabled) : Module(start_enabled)
{
	magicalRect.x = 0;
	magicalRect.y = 0;
	magicalRect.w = 1024;
	magicalRect.h = 768;

	breezeRect.x = 0;
	breezeRect.y = 0;
	breezeRect.w = 1024;
	breezeRect.h = 768;

	beatRect.x = 0;
	beatRect.y = 0;
	beatRect.w = 1024;
	beatRect.h = 768;

	waveRect.x = 0;
	waveRect.y = 0;
	waveRect.w = 1024;
	waveRect.h = 768;

//	finalize = false;
//	clock_t initT = clock();
//	initTimer = initT;
}

ModuleSceneMusic::~ModuleSceneMusic()
{}

// Load assets
bool ModuleSceneMusic::Start()
{
	LOG("Loading sega scene");

	magicalTexture = App->textures->Load(MAGICALPATH);
	breezeTexture = App->textures->Load(BREEZEPATH);
	waveTexture = App->textures->Load(WAVEPATH);
	beatTexture = App->textures->Load(BEATPATH);
	//music2 = App->audio->LoadFx("Sound\\02-Passing-Breeze.wav");
	//App->audio->PlayFx(music2, 1);
	finalize = false;
	musicCount = 0;
	secondsToQuit = 10;
	return true;
}
// UnLoad assets
bool ModuleSceneMusic::CleanUp()
{
	LOG("Unloading sega scene");

	App->textures->Unload(beatTexture);
	App->textures->Unload(waveTexture);
	App->textures->Unload(breezeTexture);
	App->textures->Unload(magicalTexture);
	
	return true;
}
// Update: draw background
update_status ModuleSceneMusic::Update()
{
//	if (!finalize) {
		secondsPassed = (clock() - initTimer) / CLOCKS_PER_SEC;
		switch (musicCount)
		{
		case 0:
			App->renderer->Blit(magicalTexture, 0, 0, &magicalRect, 0.25f);
			break;
		case 1:
			App->renderer->Blit(breezeTexture, 0, 0, &breezeRect, 0.25f);
			break;
		case 2:
			App->renderer->Blit(waveTexture, 0, 0, &waveRect, 0.25f);
			break;
		case 3:
			App->renderer->Blit(beatTexture, 0, 0, &beatRect, 0.25f);
			break;
		default:
			musicCount = 0;
			break;
		}

		if ((int)secondsPassed % 3 == 0)App->fonts->PrintCharacter(App->fonts->greenFonts, 325, 500, "PRESS SPACE BUTTON");
		App->fonts->PrintCharacter(App->fonts->pinkFonts, 100, 700, "CREDIT 1");
		if (App->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN)musicCount -= 1;
		if (App->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN)musicCount += 1;
		if (musicCount < 0)musicCount = 3;
		if (musicCount > 3)musicCount = 0;
		if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN && App->fade->isFading() == false) {
			App->fade->FadeToBlack((Module*)App->scene_stage, this);
			//finalize = true;
			//CleanUp();
		}
	//}
	return UPDATE_CONTINUE;
}
