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
		
	//flag.frames.push_back({ 971, 88 , 35 , 93, });
	//flag.frames.push_back({ 959, 183 , 47, 91, });
	//flag.frames.push_back({ 952, 274 , 53, 65, });
	//flag.frames.push_back({ 952, 339 , 50, 66, });
	//flag.frames.push_back({ 951, 407 , 52, 74, });
	//flag.frames.push_back({ 955, 483 , 50, 81, });

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
	StartFlag->rect = { 340, 2,887 , 75 };
//	StartFlag->rect={339, 256, 59, 111};
	Rects.push_back(StartFlag);
	sfpos = Rects.size() - 1;

	Rect * FinishFlag = new Rect();
	FinishFlag->rect = { 532, 888, 587, 75 };
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
	//People1->rect = { 528, 720, 238, 161 };
	People1->rect = { 529, 601, 148, 226 };
	Rects.push_back(People1);
	peopos1 = Rects.size() - 1;

	Rect * People2 = new Rect();
	//People2->rect = { 786, 730, 195, 130 };
	People2->rect = { 703, 717, 139, 95 };
	Rects.push_back(People2);
	peopos2 = Rects.size() - 1;

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

//	Rect * Ocean2 = new Rect();
//	Ocean2->rect = { 10, 665, 243, 31 };
//	Rects.push_back(Ocean2);
//	oceanpos2 = Rects.size() - 1;
//
//	Rect* Ocean2 = new Rect();
//	Ocean2->rect = { 10, 665, 243, 31 };
//	Rects.push_back(Ocean2);
//	oceanpos2 = Rects.size() - 1;
	countSequence=0;
	start.x = 339;
	start.y = 3;
	start.w = 588;
	start.h = 75;
	Rect* Car1 = new Rect();
	Car1->rect = { 30, 7, 39, 30 };
	Rects.push_back(Car1);
	car1pos = Rects.size() - 1;

	//animations
	ocean.frames.push_back({ 10,373,243,31 });
	ocean.frames.push_back({ 10,665,243,31 });

	trafficLight.frames.push_back({ 600,303,73,127 });
	trafficLight.frames.push_back({ 680,303,73,127 });
	trafficLight.frames.push_back({ 765,303,73,127 });
	trafficLight.frames.push_back({ 845,303,73,127 });

	trafficLight.speed = 0.01f;
	//flag.speed = 0.1f;
	float transitionValue;
	for (int i = 0; i <11000; i++)
	{
		Line line;
		line.zc = (float)i * 100;

		if (0<i && i<780) {
			if (i == 24) {
				line.position = peopos1;
				line.spriteX = -0.6f;
			}
			if (i == 25) {
				line.position = peopos2;
				line.spriteX = 0.6f;
			}

			if (i<390 && !(i>=24 && i<=26)) {
				if (i % 20 == 0) {
					line.position = harrowpos;
					line.spriteX = -1.5f;
					line.scale = 3;
					line.elevate = -10;
				}
				if (i % 21 == 0) {
					line.position = ptbpos;
					line.spriteX = 1.5f;
					line.elevate = -10;
				}
			}
			else {
				if (i % 20 == 0 &&!(i >= 24 && i <= 26)) {
					line.position = ptspos;
					line.spriteX = 1.5f;
					line.elevate = -5;
				}
				if (i % 21 == 0 &&!(i >= 24 && i <= 26)) {
					line.position = ptspos;
					line.spriteX = -1.5f;
					line.elevate = -5;
				}
			}
			transitionValue = (float)(sin(3.14*i / 300) * 2750);
			if (-0.1 < transitionValue < 0.1) line.yc = -transitionValue;
			if(350<i && i < 400)line.curve = LOWCURVELEFT;
			if (i == 779) lastValue = line.yc;
			if (400 < i && i < 500)line.curve = NOTCURVE;
			//if (i == 30) {
			//	line.position = car1pos;
			//	line.spriteX = 0;
			//	line.elevate = -5;
			//}
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
					line.elevate = -5;
				}if (i % 21 ==0) {
					//line.position = ffpos;
					//line.spriteX = 0;
					//line.scale = 3;
					//line.elevate = -50;
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
				line.elevate = -10;
			}
		}
		if (2340<i && i<3120) { 
			line.curve = LOWCURVERIGHT; 
			if (i % 2 == 0) {
				line.position = oceanpos;
				line.spriteX = -2;
				line.elevate = -10;
			}
			else {
				line.position = oceanpos2;
				line.spriteX = -2;
				line.elevate = -10;
			}
			if (i % 20 == 0) {
				line.position = rppos;
				line.spriteX = -1.5;
				line.elevate = -10;
			}

		}
		if (3120<i && i<3900) { 
			line.curve = NOTCURVE; 
			if (i % 2 == 0) {
				line.position = oceanpos;
				line.spriteX = -2;
				line.elevate = -10;
			}
			else {
				line.position = oceanpos2;
				line.spriteX = -2;
				line.elevate = -10;
			}
			if (i % 20 == 0) {
				line.position = surpos;
				line.spriteX = -2;
				line.elevate = -10;
			}
			if (i % 25 == 0) {
				line.position = h1pos;
				line.spriteX = 1.5;
				line.elevate = -10;
				line.scale = 3.5;
			}

		}
		if (3900<i && i<4680) { 
			line.curve = LOWCURVELEFT; 			
			if (i % 20 == 0) {
				line.position = lppos;
				line.spriteX = 1.5;
				line.elevate = -10;
			}
		}
		if (4680<i && i<5460) { 
			line.curve = HIGHCURVELEFT; 
			if (i % 20 == 0) {
				line.position = lppos;
				line.spriteX = 1.5;
				line.elevate = -10;
			}
		}
		if (5460 < i && i < 6240) { 
			line.curve = NOTCURVE;
			if (i == 6000) {
				line.position = ffpos;
				line.spriteX = 0;
				line.elevate = -20;
				line.scale = 3;
				line.elevate = -50;
			}
			else {
				line.position = oceanpos;
				line.spriteX = -1.5;
				line.elevate = -10;
			}
		}
		if (6240<i && i<7020) { 
			line.curve = HIGHCURVERIGHT; 
			if (i % 20 == 0) {
				line.position = rppos;
				line.spriteX = -1.5;
				line.elevate = -10;
			}
		}
		if (7020<i && i<7800) { 
			line.curve = HIGHCURVELEFT; 
			if (i % 20 == 0) {
				line.position = lppos;
				line.spriteX = 1.5;
				line.elevate = -10;
			}
		}
		if (7800<i && i<8580) { 
			line.curve = HIGHCURVELEFT; 
			if (i % 20 == 0) {
				line.position = lppos;
				line.spriteX = 1.5;
				line.elevate = -10;
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
					line.elevate = -10;
				}
			}
			if (i == 10139) lastValue = line.yc;
			if (400 < i && i < 500) {
				line.curve = NOTCURVE;

			}
		}
		if (10140<i && i<10999) {
			if (i==450) {
				line.position = ffpos;
				line.spriteX = 0;
				line.elevate = -10;
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
	landscape = App->textures->Load(BACKGROUND);
	Stage1 = App->textures->Load(STAGE);
	Uinterface = App->textures->Load(MARKERPATH);
	App->audio->PlayMusic(SOUNDBREEZEPATH, 1.0f);
	//App->fade->FadeToBlack((Module*)App->player, nullptr);
	App->player->Start();
	score = 0;
	N = lines.size();
	pos = 0;
	playerX = 0;
	playerY = 0;
	clock_t initT = clock();
	initTimer = initT;
	minuteLap = 0;
	secondsLap = 0;
	miliSecondsLap = 0;
	//MODI
	countSequence = 0;
	secondsToQuit = 100;
	secondsAux = 0;
	HiVelocity = false;
	vel = 0;
	auxPos = -1;
	finish = false;
	return true;
}
// UnLoad assets
bool ModuleSceneStage::CleanUp()
{
	LOG("Unloading sega scene");
	//App->audio->CleanUp();
	App->player->CleanUp();
	App->textures->Unload(Uinterface);
//	App->textures->Unload(playerimage);
	App->textures->Unload(Stage1);
	App->textures->Unload(landscape);

	return true;
}

update_status ModuleSceneStage::Update()
{
	//Timer
	if (SECONDSPASSED > 2) {
		if (TimePlaying() && !finish) {

			if (App->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
			{
				growVelocity();
				if (countSequence < 500)countSequence += 15;
			}
			else {
				reduceVelocity();
			}
			if (App->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
			{
				if (!HiVelocity) { if (vel != 0)playerY -= 85; App->player->animations = 1; }
				else { if (vel != 0)playerY -= 125; App->player->animations = 2; }

			}
			else if (App->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
			{
				if (!HiVelocity) { if (vel != 0)playerY += 85; App->player->animations = 3; }
				else { if (vel != 0)playerY += 125; App->player->animations = 4; }

			}
			else {
				//App->player->animations = 0;
			}
			if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
			{
				if (!HiVelocity)HiVelocity = true;
				else HiVelocity = false;
			}
			if (playerY > 3500)playerY = 3500;
			if (playerY < -3500)playerY = -3500;
		}
		else {
			SDL_Delay(2000);
			App->audio->QuitSoundtrack(1.0f);
			if (App->fade->isFading() == false)App->fade->FadeToBlack((Module*)App->scene_sega, this);
		}
	}
	
	reDrawRoad();
	if (countSequence<490)scenarioBegin();
	//App->renderer->Blit(landscape, 0, -25, &background, 1);


	UserInterface();
//Posició normal
	//if(vel==0)App->player->animations = 0;
	App->player->printPlayer();//animations = 0;
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
	//App->renderer->Blit(landscape, 0, -150, &background, 1);
	App->renderer->Blit(landscape, 0, -150, &background, 1);
	if (vel != 0) {
		if (lines[startPos + 25 % N].curve == LOWCURVELEFT   && vel != 0 && TimePlaying()) { playerY += 25; App->player->animations = 1; }
		else
			if (lines[startPos + 25 % N].curve == HIGHCURVELEFT  && vel != 0 && TimePlaying()) { playerY += 50; App->player->animations = 2; }
			else
				if (lines[startPos + 25 % N].curve == LOWCURVERIGHT  && vel != 0 && TimePlaying()) { playerY -= 25; App->player->animations = 3; }
				else
					if (lines[startPos + 25 % N].curve == HIGHCURVERIGHT && vel != 0 && TimePlaying()) { playerY -= 50; App->player->animations = 4; } else
						if (lines[startPos + 25 % N].curve == NOTCURVE && vel != 0 && TimePlaying() && (!INPUTLEFT || !INPUTRIGHT)) { App->player->animations = 0; }//else
	}
	if (lines[startPos % N].position == ffpos)finish = true;
	//if (lines[startPos + 25 % N].zc)countSequence++;

	for (int n = startPos; n < startPos + 300; n++) {
		Line &current = lines[n%N];

		current.projection((int)(playerY - x), camH, seg_pos - (n >= N ? N * 200 : 0));
		x += dx;
		dx += current.curve;
		
		current.clip = maxy;
		if (current.Y >= maxy) continue;
		maxy = (current.Y);

		RGBA beach = (n / 3) % 2 ? RGBA(222, 192, 131, 255) : BEACH1;
		RGBA rumble = (n / 3) % 2 ? RGBA(107, 107, 107, 255) : ROAD2;
		RGBA rumble2 = (n / 3) % 2 ? RGBA(128, 128, 128, 255) : ROAD1;
		RGBA line = (n / 3) % 2 ? RGBA(255, 255, 255, 255) : ROAD2;
		if (n == 0)n++;
		
		Line previous = lines[(n - 1) % N];

		redrawPoly(beach, 0, (short)previous.Y, SCREEN_WIDTH, 0, (short)current.Y, SCREEN_WIDTH);
		redrawPoly(line, (short)previous.X, (short)previous.Y, (short)(previous.W*1.15), (short)current.X, (short)current.Y, (short)(current.W*1.15));
		redrawPoly(rumble, (short)previous.X, (short)previous.Y, (short)(previous.W*1.03), (short)current.X, (short)current.Y, (short)(current.W*1.03));		
		redrawPoly(rumble2, (short)previous.X, (short)previous.Y, (short)previous.W, (short)current.X, (short)current.Y, (short)current.W);
		redrawPoly(line, (short)previous.X, (short)previous.Y, (short)(previous.W*0.05), (short)current.X, (short)current.Y, (short)(current.W*0.05));
	}
	
		for (int n = startPos + 199; n >= startPos; n--) {
			if (lines[n%N].position != -1) {
				//if (lines[n%N].position == ffpos)lines[n%N].DrawFinishCheck(Rects[lines[n%N].position]->rect, Stage1, lines[n%N].elevate);
				lines[n%N].DrawObject(Rects[lines[n%N].position]->rect, Stage1, lines[n%N].elevate);
			}		
		}
		for (int n = startPos + 199; n >= startPos; n--) {
			if (lines[n%N].position != -1) {
				lines[n%N].DrawObject(Rects[lines[n%N].position]->rect, Stage1, lines[n%N].elevate);
			}
		}
		if(!TimePlaying())App->fonts->PrintCharacter(App->fonts->purpleFonts, 400, 500, "GAME OVER!");
		if(finish)App->fonts->PrintCharacter(App->fonts->purpleFonts, 300, 500, "CONGRATULATIONS YOU WIN!");
}

bool ModuleSceneStage::TimePlaying() {
	secondsPassed = SECONDSPASSED;
	if (secondsPassed>2)
	{
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
		if (secondsToQuit <= 0) {
			return false;
		}
	}
	return true;
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
	//Comprovació de Pos per pantalla
	//App->fonts->PrintVelocity(App->fonts->velocity, 50, 650, std::to_string(line.yc));
	App->fonts->PrintVelocity(App->fonts->velocity, 50, 650, std::to_string(vel));
	App->renderer->Blit(Uinterface, 165, 650, &markerKMh, 1);
	if (!HiVelocity) App->fonts->PrintCharacter(App->fonts->purpleFonts, 275, 675, "LOW");//itoa(App->scene_sega->score));;
	else App->fonts->PrintCharacter(App->fonts->greenFonts, 275, 650, "HI");//itoa(App->scene_sega->score));;
}

void ModuleSceneStage::scenarioBegin() {

	App->renderer->ScaledBlit(Stage1, -175, 400, &gradas, 1,1.5,1.5);
	//App->renderer->ScaledBlit(Stage1, -650, 450, &gradas, 1,3,3);
	App->renderer->Blit(Stage1, 765+countSequence, 400, &palmatreeSmall, 1);
	
//	App->renderer->Blit(Stage1, 165, 650, &rightPanel, 1);
//	App->renderer->Blit(Stage1, 165, 650, &leftPanel, 1);
	App->renderer->ScaledBlit(Stage1, 50, 100- countSequence, &start,0.25f, 1.5, 1.5);
	App->renderer->ScaledBlit(Stage1, 25- countSequence, 150 + countSequence, &(trafficLight.GetCurrentFrame()), 1,3,3);
	App->renderer->ScaledBlit(Stage1, 750+ countSequence, 150 + countSequence, &(trafficLight.GetCurrentFrame()), 1, 3, 3);
	App->renderer->ScaledBlit(Stage1, 800+countSequence, 50, &palmatreeBig, 1, 3, 3);
	if (secondsPassed < 3) {
		flag.x = 971;
		flag.y = 88;
		flag.w = 35;
		flag.h = 93;
		App->renderer->ScaledBlit(Stage1, 200 - countSequence, 300+countSequence, &flag, 0.8f, 3, 3);
	}else {
		flag.x = 951;
		flag.y = 407;
		flag.w = 52;
		flag.h = 74;
		App->renderer->ScaledBlit(Stage1, 200 - countSequence, 350 + countSequence, &flag, 0.8f, 3, 3);
	}
	//flag.frames.push_back({ 971, 88 , 35 , 93, });
	//flag.frames.push_back({ 959, 183 , 47, 91, });
	//flag.frames.push_back({ 952, 274 , 53, 65, });
	//flag.frames.push_back({ 952, 339 , 50, 66, });
	//flag.frames.push_back({ 951, 407 , 52, 74, });
	//flag.frames.push_back({ 955, 483 , 50, 81, });

	//App->renderer->ScaledBlit(Stage1, 20, 400, &people1, 1,1.5,1.5);
	//App->renderer->ScaledBlit(Stage1, 650, 400, &people2, 1,1.5,1.5);
//	App->renderer->ScaledBlit(Stage1, 225, 390, &flag, 0.01f,3,3);
	//App->renderer->Blit(Stage1, 165, 650, &harrow, 1);

}
