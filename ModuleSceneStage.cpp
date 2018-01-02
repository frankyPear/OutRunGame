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
#include "Line.h"
#include "SDL/include/SDL2_gfxPrimitives.c"
#include "SDL/include/SDL2_rotozoom.c"
#include "ModuleSceneStage.h"
#include <string>
#include <ctime>
#include <time.h>
vector<Line>lines;

ModuleSceneStage::ModuleSceneStage(bool start_enabled) : Module(start_enabled)
{
	background.x = 0;
	background.y = 100;
	background.w = 2257;
	background.h = 454;
	
	markerUITime.x = 27;
	markerUITime.y = 9;
	markerUITime.w = 143;
	markerUITime.h = 53;

	markerUIScore.x = 187;
	markerUIScore.y = 9;
	markerUIScore.w = 171;
	markerUIScore.h = 53;

	markerUILap.x = 384;
	markerUILap.y = 9;
	markerUILap.w = 125;
	markerUILap.h = 53;

	markerUIMap.x = 536;
	markerUIMap.y = 13;
	markerUIMap.w = 67;
	markerUIMap.h = 41;

	markerKMh.x = 614;
	markerKMh.y = 4;
	markerKMh.w = 87;
	markerKMh.h = 53;

	playerAnimation.frames.push_back({208,198,76,40});
	playerAnimation.frames.push_back({ 208,198,76,40 });
	for (int i = 0; i <10000; i++)
	{
		Line line;
		line.zc = (float)i * 100;
		line.yc += currentAlture + modAlture;
		currentAlture = line.yc;

		line.curve = 0;
		if (i > 300 && i < 700) line.curve = 4;
		if (i > 500 && i < 600) line.curve = -1;

		lines.push_back(line);
	}
	N = lines.size();
	pos = 0;


}
ModuleSceneStage::~ModuleSceneStage()
{}


// Load assets
bool ModuleSceneStage::Start()
{
	LOG("Loading sega scene");
	landscape = App->textures->Load("Background\\OutRunBackground1.png");
	playerimage = App->textures->Load("player.png");
	Uinterface = App->textures->Load(MARKERPATH);
	App->fonts->PrintVelocity(App->fonts->velocity, 225, 70, "000");
	//music2 = App->audio->LoadFx("Sound\\01-Magical-Sound-Shower.ogg");
	//App->audio->PlayFx(music2, 1);

	score = 0;
	N = lines.size();
	pos = 0;
	playerX = 0;
	clock_t initT = clock();
	initTimer = initT;
	minuteLap = 0;
	secondsLap = 0;
	miliSecondsLap = 0;
	secondsToQuit = 60;
	secondsAux = 0;
	return true;
}
// UnLoad assets
bool ModuleSceneStage::CleanUp()
{
	LOG("Unloading sega scene");
	App->textures->Unload(Uinterface);
	return true;
}

update_status ModuleSceneStage::Update()
{
	//Timer
	TimeManager();

	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		pos += 300;
		score += 20;
	}
	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{
		playerX -= 300;
	}

	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		playerX += 300;
	}


	reDrawRoad();
	App->renderer->Blit(landscape, 0, 0, &background, 1);
	UserInterface();
	App->renderer->Blit(playerimage, (SCREEN_WIDTH / 2) - (208 / 2) + 76, (SCREEN_HEIGHT - 80), &(playerAnimation.GetCurrentFrame()), 0.25f);
	return UPDATE_CONTINUE;


}
bool ModuleSceneStage::redrawPoly(RGBA c, short x1, short y1, short w1, short x2, short y2, short w2)
{
	short s[4] = { x1 - w1, x2 - w2, x2 + w2, x1 + w1 };
	short t[4] = { y1, y2, y2, y1 };

	filledPolygonRGBA(App->renderer->renderer,
		s, t,
		4,
		c.r, c.g, c.b, c.a);
	return true;
}
void ModuleSceneStage::reDrawRoad()
{
	seg_pos = pos;
	if (pos % 100 != 0)
	{
		seg_pos = 100 * (pos / 100);
	}

	while (seg_pos >= N * 100)
	{
		seg_pos -= N * 100;
	}
	while (seg_pos < 0)
	{
		seg_pos += N * 100;
	}

	float x = 0, dx = 0;
	int startPos = seg_pos / 100;
	int camH = (int)(1500 + lines[startPos].yc);
	float maxy = SCREEN_HEIGHT;

	/*ROAD1 RGBA(107, 107, 107, 255);
	ROAD2 RGBA(128, 128, 128, 255);
	BLANK RGBA(255,255,255,255);
	RED RGBA(255,0,0,255);
	BEACH1 RGBA(192, 192, 160, 255);*/

	for (int n = startPos; n < startPos + 300; n++) {
		RGBA beach = (n / 3) % 2 ? RGBA(222, 192, 131, 255) : BEACH1;//currentBiome.grassDark : currentBiome.grassLight;
		RGBA rumble = (n / 3) % 2 ? RGBA(107, 107, 107, 255) : ROAD2;
		RGBA rumble2 = (n / 3) % 2 ? RGBA(128, 128, 128, 255) : ROAD1;
		RGBA line = (n / 3) % 2 ? RGBA(255, 255, 255, 255) : ROAD2;

		Line &current = lines[n%N];
		current.projection((int)(playerX - x), camH, seg_pos - (n >= N ? N * 100 : 0));
		x += dx;
		dx += current.curve;
		
		current.clip = maxy;
		if (current.Y >= maxy) continue;
		maxy = (int)(current.Y);

		Line previous = lines[(n - 1) % N];

		int laneNumber = 50;
		for (int i = laneNumber; i > 0; i--) {
			if ((short)previous.Y != (short)current.Y) {
				redrawPoly(beach, (short)previous.X, (short)previous.Y, (short)(previous.W*0.3*i), (short)current.X, (short)current.Y, (short)(current.W*0.3*i));
			}
		}
		redrawPoly(rumble, (short)previous.X, (short)previous.Y, (short)(previous.W*1.03), (short)current.X, (short)current.Y, (short)(current.W*1.03));

		redrawPoly(line, (short)previous.X, (short)previous.Y, (short)(previous.W*0.05), (short)current.X, (short)current.Y, (short)(current.W*0.05));
	}


}

void ModuleSceneStage::ChangeAltitude(float &altitudeVariation, float targetVariation, int currentSegment, int startingSegment, int endSegment, int heldSegments) {
	int segmentsToMidpoint = (endSegment - startingSegment - heldSegments) / 2;
	float variation = (float)targetVariation / segmentsToMidpoint;

	if (currentSegment <= startingSegment + segmentsToMidpoint) {
		altitudeVariation += variation;
	}
	else if (currentSegment >= startingSegment + segmentsToMidpoint + heldSegments) {
		altitudeVariation -= variation;
	}
	if (currentSegment == endSegment) {
		altitudeVariation = 0;
	}
}

void ModuleSceneStage::TimeManager() {
	secondsPassed = (clock() - initTimer) / CLOCKS_PER_SEC;
	if (secondsAux != secondsPassed) {
		secondsAux = secondsPassed;
		secondsToQuit--;
		secondsLap++;
	}
	miliSecondsLap++;
	miliSecondsLap++;
	if (secondsLap == 60) {
		secondsLap = 0;
		minuteLap++;
	}
	if (miliSecondsLap == 60)miliSecondsLap = 0;
}

void ModuleSceneStage::UserInterface() {
	App->renderer->Blit(Uinterface, 50, 50, &markerUITime, 1);
	if (secondsToQuit >= 0)
		App->fonts->PrintCharacter(App->fonts->yellowFonts, 225, 70, std::to_string(secondsToQuit));
	else
		App->fonts->PrintCharacter(App->fonts->yellowFonts, 225, 70, "0");
	App->renderer->Blit(Uinterface, 300, 50, &markerUIScore, 1);
	App->fonts->PrintCharacter(App->fonts->purpleFonts, (SCREEN_WIDTH / 2) - (208 / 2) + 100, 70, std::to_string(score));//itoa(App->scene_sega->score));
	App->renderer->Blit(Uinterface, 700, 50, &markerUILap, 1);
	App->fonts->PrintCharacter(App->fonts->greenFonts, 850, 70, std::to_string(minuteLap) + ":" + std::to_string(secondsLap) + "::" + std::to_string(miliSecondsLap));
	App->renderer->Blit(Uinterface, 950, 680, &markerUIMap, 1);
	App->fonts->PrintCharacter(App->fonts->yellowFonts, 800, 700, "STAGE 1");

	App->fonts->PrintVelocity(App->fonts->velocity, 50, 650, std::to_string(pos/25));
	App->renderer->Blit(Uinterface, 165, 650, &markerKMh, 1);
}
