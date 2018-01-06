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
	countSequence++;
	background.x = 0;
	background.y = 100;
	background.w = 2257;
	background.h = 554;
	
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

	gradas.x = 418;
	gradas.y = 183;
	gradas.w = 187;
	gradas.h = 65;
	
	Rect* PalmTreeBig = new Rect();
	PalmTreeBig->rect = { 4, 108, 98, 210 };
	Rects.push_back(PalmTreeBig);
	ptbpos = Rects.size()-1;

	Rect* PalmTreeSmall = new Rect();
	PalmTreeSmall->rect = { 5, 5, 160, 98 };
	//Rects.push_back(PalmTreeBig);
	Rects.push_back(PalmTreeSmall);
	ptspos = Rects.size() - 1;

	Rect* RightPanel = new Rect();
	RightPanel->rect = { 428, 255, 59, 111 };
	Rects.push_back(RightPanel);
	rppos = Rects.size() - 1;

	Rect* LeftPanel = new Rect();
	LeftPanel->rect = { 533, 256, 59, 111 };
	Rects.push_back(LeftPanel);
	lppos = Rects.size() - 1;

	Rect * StartFlag = new Rect();
	StartFlag->rect={339, 256, 59, 111};
	Rects.push_back(StartFlag);
	sfpos = Rects.size() - 1;

	Rect * FinishFlag = new Rect();
	FinishFlag->rect = { 532, 537, 588, 75 };
	Rects.push_back(FinishFlag);
	ffpos = Rects.size() - 1;

	Rect * House1 = new Rect();
	House1->rect = { 339, 85, 118, 85 };
	Rects.push_back(House1);
	h1pos = Rects.size() - 1;

	Rect * House2 = new Rect();
	House2->rect = { 525, 623, 118, 85 };
	Rects.push_back(House2);
	h1pos = Rects.size() - 1;
	
	Rect * Surfer = new Rect();
	Surfer->rect = { 545, 550, 51, 65 };
	Rects.push_back(Surfer);
	surpos = Rects.size() - 1;

	Rect * People1 = new Rect();
	People1->rect = { 528, 720, 238, 161 };
	Rects.push_back(People1);
	surpos = Rects.size() - 1;

	Rect * People2 = new Rect();
	People2->rect = { 786, 730, 195, 130 };
	Rects.push_back(People2);
	surpos = Rects.size() - 1;

	Rect * Harrow = new Rect();
	Harrow->rect = { 419, 183, 187, 64 };
	Rects.push_back(Harrow);
	harrowpos = Rects.size() - 1;

	Rect * Ocean = new Rect();
	Ocean->rect = { 10, 373, 243, 31 };
	Rects.push_back(Ocean);
	oceanpos = Rects.size() - 1;

	Rect * Ocean2 = new Rect();
	Ocean2->rect = { 10, 665, 243, 31 };
	Rects.push_back(Ocean2);
	oceanpos2 = Rects.size() - 1;

	//animations
	ocean.frames.push_back({ 10,373,243,31 });
	ocean.frames.push_back({ 10,665,243,31 });

	trafficLight.frames.push_back({ 600,303,73,127 });
	trafficLight.frames.push_back({ 680,303,73,127 });
	trafficLight.frames.push_back({ 765,303,73,127 });
	trafficLight.frames.push_back({ 845,303,73,127 });


//	harrow.x = 419;
//	harrow.y = 183;
//	harrow.w = 187;
//	harrow.h = 64;

//	start.x = 339;
//	start.y = 3;
//	start.w = 588;
//	start.h = 75;
//
//	finish.x = 532;
//	finish.y = 537;
//	finish.w = 588;
//	finish.h = 75;
//
//	house1.x = 339;
//	house2.x = 525;
//	house1.y = 85;
//	house2.y = 623;
//	house1.w = 118;
//	house2.w = 118;
//	house1.h = 85;
//	house2.h = 85;


	//check.x = ;
	//check.y = ;
	//check.w = ;
	//check.h = ;



	trafficLight.speed = 0.01f;
	//flag.speed = 0.1f;
	float transitionValue;
	for (int i = 0; i <11000; i++)
	{
		Line line;
		line.zc = (float)i * 100;

		if (0<i && i<780) {	
			if (i<390) {
				if (i % 20 == 0) {
					line.position = harrowpos;
					line.spriteX = -1.5;
					line.scale = 3;
				}
				if (i % 21 == 0) {
					line.position = ptbpos;
					line.spriteX = 1.5;
				}
			}
			else {
				if (i % 20 == 0) {
					line.position = ptspos;
					line.spriteX = 1.5;
				}
				if (i % 21 == 0) {
					line.position = ptspos;
					line.spriteX = -1.5;
				}
			}
			transitionValue = (float)(sin(3.14*i / 300) * 2750);
			if (-0.1 < transitionValue < 0.1) line.yc = -transitionValue;
			if(350<i && i < 400)line.curve = LOWCURVELEFT;
			if (i == 779) lastValue = line.yc;
			if (400 < i && i < 500)line.curve = NOTCURVE;
		}
		if (780 <i && i<1560) 
		{
			
			transitionValue = (float)(sin(3.14*i / 300) * 1650);
			if(i<1400)if (-0.1 < transitionValue < 0.1) line.yc = -transitionValue;
			if (1000 < i && i < 1200) {
				line.curve = LOWCURVERIGHT;
				if (i % 20 == 0) {
					line.position = rppos;
					line.spriteX = -1.5;
				}
			}
			if (i == 1559) lastValue = line.yc;
			if (i>1200)line.curve = NOTCURVE;
		}
		if (1560<i && i<2340) { 
			line.curve = LOWCURVELEFT; 
			if (i % 20 == 0) {
				line.position = lppos;
				line.spriteX = 1.5;
			}
		}
		if (2340<i && i<3120) { 
			line.curve = LOWCURVERIGHT; 
			if (i % 2 == 0) {
				line.position = oceanpos;
				line.spriteX = -2;
			}
			else {
				line.position = oceanpos2;
				line.spriteX = -2;

			}
			if (i % 20 == 0) {
				line.position = rppos;
				line.spriteX = -1.5;
			}

		}
		if (3120<i && i<3900) { line.curve = NOTCURVE; }
		if (3900<i && i<4680) { 
			line.curve = LOWCURVELEFT; 			
			if (i % 20 == 0) {
				line.position = lppos;
				line.spriteX = 1.5;
			}
		}
		if (4680<i && i<5460) { 
			line.curve = HIGHCURVELEFT; 
			if (i % 20 == 0) {
				line.position = lppos;
				line.spriteX = 1.5;
			}
		}
		if (5460 < i && i < 6240) { line.curve = NOTCURVE;
		line.position=oceanpos;
		line.spriteX = -1.5;
		}
		if (6240<i && i<7020) { 
			line.curve = HIGHCURVERIGHT; 
			if (i % 20 == 0) {
				line.position = rppos;
				line.spriteX = -1.5;
			}
		}
		if (7020<i && i<7800) { 
			line.curve = HIGHCURVELEFT; 
			if (i % 20 == 0) {
				line.position = lppos;
				line.spriteX = 1.5;
			}
		}
		if (7800<i && i<8580) { 
			line.curve = HIGHCURVELEFT; 
			if (i % 20 == 0) {
				line.position = lppos;
				line.spriteX = 1.5;
			}
		}
		if (8580<i && i<9360) { 
			if(i<8970)line.curve = HIGHCURVERIGHT;
			else line.curve = HIGHCURVELEFT; 
		}
		if (9360<i && i<10140) {
			transitionValue = (float)(sin(3.14*i / 300) * 2750);
			if (-0.1 < transitionValue < 0.1) line.yc = -transitionValue;
			if (350 < i && i < 400) {
				line.curve = LOWCURVELEFT;
				if (i % 20 == 0) {
					line.position = lppos;
					line.spriteX = 1.5;
				}
			}
			if (i == 10139) lastValue = line.yc;
			if (400 < i && i < 500) {
				line.curve = NOTCURVE;

			}
		}
		if (10140<i && i<10999) {
			if (450) {
				line.position = ffpos;
				line.spriteX = 0;
			}
		}
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
	Stage1 = App->textures->Load("Stage\\Stage1.png");
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
	HiVelocity = false;
	vel = 0;
	auxPos = -1;
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
		if (!HiVelocity) {
			pos += 100;
			score += 20;
			vel += 1;
			auxPos = pos;
			if (vel >= 120 && vel<130)vel = 120;
			if (vel > 130)vel -=20;
		}
		else {
			pos += 200;
			score += 40;
			vel += 2;
			auxPos = pos;
			if (vel >= 300)vel = 300;
			
		}
	}
	else {
		vel -= 5;
		if (vel <= 0) {
			vel = 0;
		}
		else {
			if (!HiVelocity)pos += 100;
			else pos += 200;
		}
		if (vel <= 120)HiVelocity = false;
	}
	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		if (!HiVelocity)playerY -= 45;
		else playerY -= 85;
	}
	
	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		if (!HiVelocity)playerY -= 45;
		playerY += 85;
	}
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)// || App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		if (!HiVelocity)HiVelocity = true;
		else HiVelocity = false;
	}
	if (playerY > 3500)playerY = 3500;
	if (playerY < -3500)playerY = -3500;

	//controlVelocity();

	reDrawRoad();
	//App->renderer->Blit(landscape, 0, -25, &background, 1);
	//scenarioBegin();
	UserInterface();
	App->renderer->ScaledBlit(playerimage, (SCREEN_WIDTH / 2) - 124, (SCREEN_HEIGHT - 150), &(App->player->playerAnimation.GetCurrentFrame()), 0.25f, 3, 3);
	App->renderer->ScaledBlit(playerimage, (SCREEN_WIDTH / 2) - 65, (SCREEN_HEIGHT - 150), &(App->player->manAnimation.GetCurrentFrame()), 0.25f, 3, 3);
	App->renderer->ScaledBlit(playerimage, (SCREEN_WIDTH / 2) + 10, (SCREEN_HEIGHT - 149), &(App->player->womanAnimation.GetCurrentFrame()), 0.25f, 3, 3);
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
bool ModuleSceneStage::redrawPoly2(RGBA c, short x1, short y1, short w1, short x2, short y2, short w2)
{
	//short s[4] = { x1 - w1, x2 - w2, x2 + w2, x1 + w1 };
	// Bifurcaci� short s[4] = { x2 + w2, x1 + w1,  x1 - w1, x2 - w2 };
	short s[4] = { x1 - w1, x1+w1, (x2 + w2), (x2 - w2) };
	short t[4] = { y1, y1, y2, y2 };

	filledPolygonRGBA(App->renderer->renderer,
		s, t,
		4,
		c.r, c.g, c.b, c.a);
	return true;
}
void ModuleSceneStage::reDrawRoad()
{
	seg_pos = pos;
	if (pos % 50 != 0)
	{
		seg_pos = 50 * (pos / 50);
	}
	
	while (seg_pos >= N * 50)
	{
		seg_pos -= N * 50;
	}
	while (seg_pos < 0)
	{
		seg_pos += N * 50;
	}

	float x = 0, dx = 0;
	int startPos = seg_pos / 100;
	int camH = (int)(1500 + lines[startPos].yc);
	float maxy = SCREEN_HEIGHT;
	App->renderer->Blit(landscape, 0, -50, &background, 1);
	for (int n = startPos; n < startPos + 300; n++) {
		Line &current = lines[n%N];

		int startPos = App->player->playerX / 200;
		//float currentCurve = lines[startPos%N].curve;
		//if (currentCurve > 3.5) playerY -= 60;
		//else if (currentCurve > 2) playerY -= 45;
		//else if (currentCurve > 1) playerY -= 25;
		//else if (currentCurve > 0) playerY -= 15;
		//else if (currentCurve < 0) {
		//	if (currentCurve > -1) playerY += 15;
		//	else if (currentCurve > 2) playerY += 25;
		//	else if (currentCurve > 3.5) playerY += 45;
		//	else playerY += 60;
		//
		//}
		//playerY = 0;

		current.projection((int)(playerY - x), camH, seg_pos - (n >= N ? N * 200 : 0));
		//current.projection((int)(playerX - x), camH, seg_pos - (n >= N ? N * 200 : 0));
		x += dx;
		dx += current.curve;
		
		current.clip = maxy;
		if (current.Y >= maxy) continue;
		maxy = (current.Y);

		RGBA beach = (n / 3) % 2 ? RGBA(222, 192, 131, 255) : BEACH1;//currentBiome.grassDark : currentBiome.grassLight;
		RGBA rumble = (n / 3) % 2 ? RGBA(107, 107, 107, 255) : ROAD2;
		RGBA rumble2 = (n / 3) % 2 ? RGBA(128, 128, 128, 255) : ROAD1;
		RGBA line = (n / 3) % 2 ? RGBA(255, 255, 255, 255) : ROAD2;
		if (n == 0)n++;
		//Line &current = lines[n%N];
		//current.projection((int)(playerX - x), camH, seg_pos - (n >= N ? N * 200 : 0));
		//x += dx;
		//dx += current.curve;
		


		Line previous = lines[(n - 1) % N];

		//int laneNumber = 50;
		//for (int i = laneNumber; i > 0; i--) {
		//	if ((short)previous.Y != (short)current.Y) {
		//		redrawPoly(beach, (short)previous.X, (short)previous.Y, (short)(previous.W*0.3*i), (short)current.X, (short)current.Y, (short)(current.W*0.3*i));
		//	}
		//}
		
		redrawPoly(beach, 0, (short)previous.Y, SCREEN_WIDTH, 0, (short)current.Y, SCREEN_WIDTH);
//		redrawPoly(beach, (short)previous.X, (short)previous.Y, (short)(previous.W*0.3*n), (short)current.X, (short)current.Y, (short)(current.W*0.3*n));
		redrawPoly(line, (short)previous.X, (short)previous.Y, (short)(previous.W*1.15), (short)current.X, (short)current.Y, (short)(current.W*1.15));
		redrawPoly(rumble, (short)previous.X, (short)previous.Y, (short)(previous.W*1.03), (short)current.X, (short)current.Y, (short)(current.W*1.03));		
		redrawPoly(rumble2, (short)previous.X, (short)previous.Y, (short)previous.W, (short)current.X, (short)current.Y, (short)current.W);
		redrawPoly(line, (short)previous.X, (short)previous.Y, (short)(previous.W*0.015), (short)current.X, (short)current.Y, (short)(current.W*0.015));
	}
		//for (int n = startPos + 199; n >= startPos; n--) {

		for (int n = startPos + 199; n >= startPos; n--) {
			if (lines[n%N].position != -1) {
				lines[n%N].DrawObject(Rects[lines[n%N].position]->rect, Stage1);
			}		
		}
		for (int n = startPos + 199; n >= startPos; n--) {
			if (lines[n%N].position != -1) {
				lines[n%N].DrawCars(Cars[lines[n%N].position + 1]->cars, Stage1);
			}
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
	App->renderer->Blit(Uinterface, 675, 50, &markerUILap, 1);
	App->fonts->PrintCharacter(App->fonts->greenFonts, 825, 70, std::to_string(minuteLap) + ":" + std::to_string(secondsLap) + "::" + std::to_string(miliSecondsLap));
	App->renderer->Blit(Uinterface, 950, 680, &markerUIMap, 1);
	App->fonts->PrintCharacter(App->fonts->yellowFonts, 800, 695, "STAGE 1");
	//Comprovaci� de Pos per pantalla
	//App->fonts->PrintVelocity(App->fonts->velocity, 50, 650, std::to_string(line.yc));
	App->fonts->PrintVelocity(App->fonts->velocity, 50, 650, std::to_string(vel));
	App->renderer->Blit(Uinterface, 165, 650, &markerKMh, 1);
	if (!HiVelocity) App->fonts->PrintCharacter(App->fonts->purpleFonts, 275, 675, "LOW");//itoa(App->scene_sega->score));;
	else App->fonts->PrintCharacter(App->fonts->greenFonts, 275, 650, "HI");//itoa(App->scene_sega->score));;
}

void ModuleSceneStage::scenarioBegin() {

	countSequence++;

	App->renderer->Blit(Stage1, 175, 400, &gradas, 1);
	App->renderer->ScaledBlit(Stage1, -650, 450, &gradas, 1,3,3);
	//App->renderer->Blit(Stage1, 765, 400, &palmatreeSmall, 1);
	
//	App->renderer->Blit(Stage1, 165, 650, &(ocean.GetCurrentFrame()), 1);
//	App->renderer->Blit(Stage1, 165, 650, &rightPanel, 1);
//	App->renderer->Blit(Stage1, 165, 650, &leftPanel, 1);
	App->renderer->ScaledBlit(Stage1, 50, 100, &start,0.25f, 1.5, 1.5);
//	App->renderer->Blit(Stage1, 165, 650, &finish, 1);
//	App->renderer->Blit(Stage1, 165, 650, &house1, 1);
//	App->renderer->Blit(Stage1, 165, 650, &house2, 1);
	App->renderer->ScaledBlit(Stage1, 25, 150, &(trafficLight.GetCurrentFrame()), 1,3,3);
	App->renderer->ScaledBlit(Stage1, 750, 150, &(trafficLight.GetCurrentFrame()), 1, 3, 3);
	App->renderer->ScaledBlit(Stage1, 800, 50, &palmatreeBig, 1, 3, 3);
	//	App->renderer->Blit(Stage1, 165, 650, &surfer, 1);
	
	//App->renderer->Blit(Stage1, 200, 500, &(flag.GetCurrentFrame()), 0.8f);
	//App->renderer->ScaledBlit(Stage1, 20, 400, &people1, 1,1.5,1.5);
	//App->renderer->ScaledBlit(Stage1, 650, 400, &people2, 1,1.5,1.5);
	if (countSequence == 0) { 
		flag.x = 971; flag.y = 88; flag.w = 35; flag.h = 93; 
		App->renderer->ScaledBlit(Stage1, 225, 390, &flag, 0.1f,3,3);
	}
	if (countSequence == 1) { 
		flag.x = 959; flag.y = 183; flag.w = 47; flag.h = 91; 
		App->renderer->ScaledBlit(Stage1, 220, 395, &flag, 0.1f, 3, 3);
	}
	if (countSequence == 2) { 
		flag.x = 952; flag.y = 274; flag.w = 53; flag.h = 65; 
		App->renderer->ScaledBlit(Stage1, 215, 475, &flag, 0.1f, 3, 3);
	}
	if (countSequence == 3) { 
		flag.x = 952; flag.y = 339; flag.w = 50; flag.h = 66; 
		App->renderer->ScaledBlit(Stage1, 188, 480, &flag, 0.1f, 3, 3);
	}
	if (countSequence == 4) { 
		flag.x = 951; flag.y = 407; flag.w = 52; flag.h = 74; 
		App->renderer->ScaledBlit(Stage1, 188, 455, &flag, 0.1f, 3, 3);
	}
	if (countSequence == 5) { 
		flag.x = 955; flag.y = 483; flag.w = 50; flag.h = 81; 
		App->renderer->ScaledBlit(Stage1, 190, 450, &flag, 0.1f, 3, 3);
		countSequence = -1;
	}
	//App->renderer->Blit(Stage1, 165, 650, &harrow, 1);

}
void ModuleSceneStage::controlVelocity() {
	if (!HiVelocity) {
		if (vel > 120) {
			if (auxPos = auxPos)vel = 120;
			else vel -= 20;
		}
		else if (vel <= 120 && vel != 0) {
			if (auxPos = auxPos)vel = 120;
			else vel -= 10;
		}
		if (vel <= 0)
			vel = 0;
	}
	else {
		if (vel > 300) {
			//if (auxPos = auxPos)vel = 300;
			//else 
				vel -= 2;
		}
		else if (vel <= 120 && vel != 0) {
			//if (auxPos = auxPos)vel = 120;
			//else 
				vel -= 1;
		}
		if (vel <= 0)
			vel = 0;
	}
	//	if (!HiVelocity) {
	//		//	pos += 50;
	//			vel -= 1;
	//			//auxPos = pos;
	//	}
	//		else {
	//	//		pos += 150;
	//			vel -= 2;
	//		}
}