#include "Globals.h"
#include "Application.h"
#include "ModuleSceneKen.h"
#include "ModuleSceneSega.h"
#include "ModuleSceneGame.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleWindow.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL.h"

//#include "SDL_gfx/include/SDL_framerate.h"
//#include "SDL_gfx/include/SDL_gfxPrimitives.h"
//#include "SDL_gfx/include/SDL_gfxPrimitives_font.h"
//#include "SDL_gfx/include/SDL_imageFilter.h"
//#include "SDL_gfx/include/SDL_rotozoom.h"
//#include "SDL/include/SDL2_gfxPrimitives.c"
//#include "SDL/include/SDL2_gfxPrimitives.c"
//#include "SDL/include/SDL2_imageFilter.c"
#include <SDL_mixer.h>
#include <ctime>
//#pragma comment( lib, "SDL_gfx/libx86/sdlgfx.lib" )

ModuleSceneGame::ModuleSceneGame(bool start_enabled) : Module(start_enabled)
{
	// logo
	//logo.frames.push_back({ 8, 8, 208, 64 });
	//logo.frames.push_back({ 8, 81, 208, 64 });
	//logo.frames.push_back({ 8, 154, 208, 64 });
	//logo.frames.push_back({ 8, 227, 208, 64 });
	//logo.frames.push_back({ 8, 300, 208, 64 });
	//logo.frames.push_back({ 8, 373, 208, 64 });
	//
	//logo.frames.push_back({ 224, 8, 208, 64 });
	//logo.frames.push_back({ 224, 81, 208, 64 });
	//logo.frames.push_back({ 224, 154, 208, 64 });
	//logo.frames.push_back({ 224, 227, 208, 64 });
	//logo.frames.push_back({ 224, 300, 208, 64 });
	//logo.frames.push_back({ 224, 373, 208, 64 });
	//
	//logo.frames.push_back({ 440, 8, 208, 64 });
	//logo.frames.push_back({ 440, 81, 208, 64 });
	//logo.frames.push_back({ 440, 154, 208, 64 });
	//logo.frames.push_back({ 440, 227, 208, 64 });
	//logo.frames.push_back({ 440, 300, 208, 64 });
	//logo.frames.push_back({ 440, 373, 208, 64 });
	//
	//logo.frames.push_back({ 656, 8, 208, 64 });
	//logo.frames.push_back({ 656, 81, 208, 64 });
	//logo.frames.push_back({ 656, 154, 208, 64 });
	//
	//logo.speed = 0.25f;
	//finalize = false;
	//clock_t initT = clock();
	//initTimer = initT;
}

ModuleSceneGame::~ModuleSceneGame()
{
}

// Load assets
bool ModuleSceneSega::Start()
{
	LOG("Loading sega scene");

	graphics = App->textures->Load("SEGA.png");
	music2 = App->audio->LoadFx("02-Passing-Breeze.wav");
	App->audio->PlayFx(music2, 1);

	secondsToQuit = 10;
	return true;
}
// UnLoad assets
bool ModuleSceneSega::CleanUp()
{
	LOG("Unloading sega scene");

	App->textures->Unload(graphics);
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleSceneSega::Update()
{
	App->renderer->Blit(graphics, 216, 200, &(logo.GetCurrentFrame()), 0.01f);
	//while(!finalize){		
	secondsPassed = (clock() - initTimer) / CLOCKS_PER_SEC;
	if (secondsPassed >= secondsToQuit) {
		finalize = true;
		//exit(0);

		//int result = pixelRGBA(App->renderer->renderer, 200, 200, 255, 255, 255, 255);
		short x[6] = { 350, 275, 300, 325, 350, 400 };
		short y[6] = { 325, 325, 390, 390, 375, 300 };

		/*Fonts*/
		App->fade->FadeToBlack(App->scene_sega, nullptr, 3.0f);
		//App->scene_game->Start();



		//polygonRGBA(App->renderer->renderer,x, y,6,255, 255, 255, 155);


		//for (int n = startPos; n<startPos + 300; n++)
		//{
		//	Line &l = lines[n%N];
		//	l.project(playerX*roadW - x, camH, startPos*segL - (n >= N ? N*segL : 0));
		//	x += dx;
		//	dx += l.curve;
		//
		//	l.clip = maxy;
		//	if (l.Y >= maxy) continue;
		//	maxy = l.Y;
		//
		//	Color grass = (n / 3) % 2 ? Color(16, 200, 16) : Color(0, 154, 0);
		//	Color rumble = (n / 3) % 2 ? Color(255, 255, 255) : Color(0, 0, 0);
		//	Color road = (n / 3) % 2 ? Color(107, 107, 107) : Color(105, 105, 105);
		//
		//	Line p = lines[(n - 1) % N]; //previous line
		//
		//	drawQuad(app, grass, 0, p.Y, width, 0, l.Y, width);
		//	drawQuad(app, rumble, p.X, p.Y, p.W*1.2, l.X, l.Y, l.W*1.2);
		//	drawQuad(app, road, p.X, p.Y, p.W, l.X, l.Y, l.W);
		//}

		//App->window->GenerateRoad();//->window->
		//SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
	}
	if (finalize) {

	}

	if (App->input->GetKey(SDL_SCANCODE_ESCAPE)) {
		//App->audio->PlayFx(music, 1);
		//fade->FadeToBlack(scene_honda, nullptr, 3.0f);
		return UPDATE_STOP;
	}

	return UPDATE_CONTINUE;
}