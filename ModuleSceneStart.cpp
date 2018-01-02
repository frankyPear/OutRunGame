//#pragma comment( lib, "SDL_gfx/libx86/sdlgfx.lib" )
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
#include "Line.h"
#include "SDL/include/SDL2_gfxPrimitives.c"
#include "SDL/include/SDL2_rotozoom.c"
#include "ModuleSceneStart.h"

//int segL = 200;
//float camD = 0.84;
//int roadW = 2000;
vector<Line>lines;

ModuleSceneStart::ModuleSceneStart(bool start_enabled) : Module(start_enabled)
{
	background.x = 252;
	background.y = 62;
	background.w = 520;
	background.h = 125;
	//background.push_back({ 8, 8, 208, 64 });ç
	//background.frames.push_back({ 8, 8, 208, 64 });
	playerAnimation.frames.push_back({ 208,198,76,40 });
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


		if (i > 800 && i < 1500) {
			//ChangeAltitude(modAlture, 150.0f, i, 800, 1500);
		}

		if (i > 0) line.yc = (float)(sin(i / 30.0) * 15000);

		/*if (i > 1100 && i < 1500) {
		ChangeAltitude(altitudeVariation, -50.0f, i, 1100, 1500);
		}*/

		//if (i == 50) { line.atrezzos.push_back(make_pair(startSign, -3)); }
		//if (i == 400) { line.atrezzos.push_back(make_pair(discoNora, 1)); }
		//if (i == 500) { line.atrezzos.push_back(make_pair(lampLeft, -2)); }
		//if (i == 500) { line.atrezzos.push_back(make_pair(lampRight, 2)); }

		lines.push_back(line);
	}
	N = lines.size();
	pos = 0;
}
ModuleSceneStart::~ModuleSceneStart()
{}


// Load assets
bool ModuleSceneStart::Start()
{
	LOG("Loading sega scene");
	graphics = App->textures->Load("Fonts\\SEGA.png");

	//music2 = App->audio->LoadFx("Sound\\02-Passing-Breeze.wav");
	//App->audio->PlayFx(music2, 1);
	N = lines.size();
	pos = 0;
	playerX = 0;
	return true;
}
// UnLoad assets
bool ModuleSceneStart::CleanUp()
{
	LOG("Unloading sega scene");

	//App->textures->Unload(graphics);
	return true;
}

update_status ModuleSceneStart::Update()
{

	//App->renderer->Blit(landscape, 200, 200, &background, 0.0f);
	//short x2[4] = { 300, 325, 350, 275 };
	//short y2[4] = { 325, 325, 390, 390 };
	//short x2[4] = { SCREEN_WIDTH /2,0,SCREEN_WIDTH / 2 ,SCREEN_WIDTH }; zero en 0 lo max
	//short x2[4] = { SCREEN_WIDTH / 2,0, 5 ,5 };
	//short x3[4] = { SCREEN_WIDTH / 2,SCREEN_HEIGHT, 5 ,5 };
	////Invertint la y tenim modo espejo short 
	//short y2[4] = { SCREEN_HEIGHT,(SCREEN_HEIGHT / 2) + 5,(SCREEN_HEIGHT / 2) + 5,   SCREEN_HEIGHT  };
	////Part inferior permanent.
	//short xNOVA[4] = { 0, 0, SCREEN_WIDTH, SCREEN_WIDTH};
	//short yNOVA[4] = { (SCREEN_HEIGHT /2)+5,  SCREEN_HEIGHT, SCREEN_HEIGHT, (SCREEN_HEIGHT /2)+5};
	//if (!iteration) {
	//	//filledPolygonRGBA(App->renderer->renderer, x, y, 4, 245, 222, 179, 155);
	//	iteration = true;
	//}
	//else {
	//	//filledPolygonRGBA(App->renderer->renderer, x, y, 4, 253, 224, 170, 155);
	//	//filledPolygonRGBA(App->renderer->renderer, x, y, 4, 192, 192, 160, 255);
	//	iteration = false;
	//}
	////road1
	//int w = 5;
	////filledPolygonRGBA(App->renderer->renderer, x, y, 4, 128, 128, 128, 255);
	////filledPolygonRGBA(App->renderer->renderer, x2, y2, 4, 192, 192, 160, 255);
	//
	//

	//
	//if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	//{
	//	//playerX += 20;
	//}
	//
	//if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	//{
	//	//playerX -= 20;
	//}

	if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
	{
		pos += 250;
		//score += 200;
	}

	reDrawRoad();
	App->renderer->Blit(playerimage, (SCREEN_WIDTH / 2) - (208 / 2) + 76, (SCREEN_HEIGHT - 80), &(playerAnimation.GetCurrentFrame()), 0.25f);
	//	while (pos >= N * 200) pos -= N * 200;
	//	while (pos < 0) pos += N * 200;
	//
	//	float x = 0, dx = 0;
	//	int startPos = pos / 200;
	//	int camH = (int)(1500 + lines[startPos].yc);
	//	int maxy = SCREEN_HEIGHT;
	//
	//	for (int n = startPos; n < startPos + 300; n++) {
	//		Line &l = lines[n%N];
	//		l.projection((int)(playerX - x), camH, pos - (n >= N ? N * 200 : 0));
	//		x += dx;
	//		//dx += l.curve;
	//
	////		l.clip = maxy;
	//		if (l.Y >= maxy) continue;
	//		maxy = (int)(l.Y);
	//
	//		RGBA grass = (n / 3) % 2 ? RGBA(102, 255, 102, 255) : BEACH1;//(51, 255, 51, 255);
	//		//RGBA grass2aux = (n / 3) % 2 ? grass2 : grass2;
	//		RGBA line = (n / 10) % 2 ? RGBA(255,255,255,255) : ROAD1;
	//
	//		Line p;
	//		//if (n == 0)
	//		//	p = lines[lines.size() - 1 % N]; //previous line
	//		//else
	//		p = lines[(n - 1) % N]; //previous line
	//
	//		int numRalles = 100;
	//		//App->renderer->DrawPoly(grass, 0, (short)p.Y, (short)p.width, 0, (short)l.Y, (short)l.width);
	//		for (int i = numRalles; i > 0; i--) {
	//			if (i % 2 == 0) {
	//				redrawPoly(RGBA(107,107,107,255), (short)p.X, (short)p.Y, (short)(p.W*0.3*i), (short)l.X, (short)l.Y, (short)(l.W*0.3*i));
	//			}
	//			else {
	//				redrawPoly(RGBA(128, 128, 128, 255), (short)p.X, (short)p.Y, (short)(p.W*0.3*i), (short)l.X, (short)l.Y, (short)(l.W*0.3*i));
	//			}
	//		}
	//		//App->renderer->DrawPoly(Green, (short)p.X, (short)p.Y, (short)(p.W*0.1), (short)l.X, (short)l.Y, (short)(l.W*0.01));
	//		//App->renderer->DrawPoly(grass2aux, (short)p.X, (short)p.Y, (short)(p.W*0.05), (short)l.X, (short)l.Y, (short)(l.W*0.05));
	//		//App->renderer->DrawPoly(rumble, (short)p.X, (short)p.Y, (short)(p.W*1.2), (short)l.X, (short)l.Y, (short)(l.W*1.2));
	//		//App->renderer->DrawPoly(color_road, (short)p.X, (short)p.Y, (short)p.W, (short)l.X, (short)l.Y, (short)l.W);
	//		//App->renderer->DrawPoly(line, (short)p.X, (short)p.Y, (short)(p.W*0.05), (short)l.X, (short)l.Y, (short)(l.W*0.05));
	//	}

	//Draw background
	//App->renderer->Blit(graphics, 0, 0, &background, 0.0f);
	//App->renderer->Blit(graphics, 0, SCREEN_HEIGHT / 2 + 7, &backgroundParalax, .05f, true);
	//App->renderer->Blit(graphics, 610, SCREEN_HEIGHT / 2 + 7, &backgroundParalax, .05f, true);
	//App->renderer->Blit(graphics, -610, SCREEN_HEIGHT / 2 + 7, &backgroundParalax, .05f, true);
	return UPDATE_CONTINUE;


}
bool ModuleSceneStart::redrawPoly(RGBA c, short x1, short y1, short w1, short x2, short y2, short w2)
{
	short s[4] = { x1 - w1, x2 - w2, x2 + w2, x1 + w1 };
	short t[4] = { y1, y2, y2, y1 };

	filledPolygonRGBA(App->renderer->renderer,
		s, t,
		4,
		c.r, c.g, c.b, c.a);
	return true;
}
void ModuleSceneStart::reDrawRoad()
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

	//if ((int)landscapePositionX < -SCREEN_WIDTH) {
	//	landscapePositionX = landscapePositionX + SCREEN_WIDTH;
	//}
	//if ((int)landscapePositionX > SCREEN_WIDTH) {
	//	landscapePositionX = landscapePositionX - SCREEN_WIDTH;
	//}

	//if ((int)foregroundPositionX < -SCREEN_WIDTH) {
	//	foregroundPositionX = foregroundPositionX + SCREEN_WIDTH;
	//}
	//if ((int)foregroundPositionX > SCREEN_WIDTH) {
	//	foregroundPositionX = foregroundPositionX - SCREEN_WIDTH;
	//}

	//App->renderer->Blit(graphics, (int)landscapePositionX, (int)landscapePositionY - currentBiome.background1.h * 2 + 2, &currentBiome.background1, 0.0f, false, false, 2, 2);
	//App->renderer->Blit(graphics, (int)landscapePositionX - SCREEN_WIDTH, (int)landscapePositionY - currentBiome.background1.h * 2 + 2, &currentBiome.background1, 0.0f, false, false, 2, 2);
	//App->renderer->Blit(graphics, (int)landscapePositionX + SCREEN_WIDTH, (int)landscapePositionY - currentBiome.background1.h * 2 + 2, &currentBiome.background1, 0.0f, false, false, 2, 2);
	//
	//App->renderer->Blit(graphics, (int)foregroundPositionX, (int)landscapePositionY - currentBiome.background2.h * 2 + 2, &currentBiome.background2, 0.0f, false, false, 2, 2);
	//App->renderer->Blit(graphics, (int)foregroundPositionX - SCREEN_WIDTH, (int)landscapePositionY - currentBiome.background2.h * 2 + 2, &currentBiome.background2, 0.0f, false, false, 2, 2);
	//App->renderer->Blit(graphics, (int)foregroundPositionX + SCREEN_WIDTH, (int)landscapePositionY - currentBiome.background2.h * 2 + 2, &currentBiome.background2, 0.0f, false, false, 2, 2);

	for (int n = startPos; n < startPos + 200; n++) {
		RGBA grass = (n / 3) % 2 ? RGBA(222, 192, 131, 255) : BEACH1;//currentBiome.grassDark : currentBiome.grassLight;
		RGBA rumble = (n / 3) % 2 ? RGBA(107, 107, 107, 255) : ROAD2;
		RGBA line = (n / 3) % 2 ? RGBA(255, 255, 255, 255) : ROAD2;
		/*ROAD1 RGBA(107, 107, 107, 255);
		ROAD2 RGBA(128, 128, 128, 255);
		BLANK RGBA(255,255,255,255);
		RED RGBA(255,0,0,255);
		BEACH1 RGBA(192, 192, 160, 255);*/
		Line &current = lines[n%N];
		current.projection((int)(playerX - x), camH, seg_pos - (n >= N ? N * 100 : 0));
		x += dx;
		dx += current.curve;
		//
		//if (n == startPos && App->player->state != ModulePlayer::PAUSE) {
		//	if (current.curve > 0) {
		//		App->player->AlterXPosition(-App->player->GetSpeed() / 6);
		//		landscapePositionX -= App->player->GetSpeed() / (float)landscapeParallaxFactor;
		//		foregroundPositionX -= App->player->GetSpeed() / (float)foregroundParallaxFactor;
		//	}
		//	else if (current.curve < 0) {
		//		App->player->AlterXPosition(App->player->GetSpeed() / 6);
		//		landscapePositionX += App->player->GetSpeed() / (float)landscapeParallaxFactor;
		//		foregroundPositionX += App->player->GetSpeed() / (float)foregroundParallaxFactor;
		//	}
		//}
		//
		//current.clip = maxy;
		//if (current.Y >= maxy) continue;
		//maxy = current.Y;

		Line previous;
		if (n == 0)
			previous = lines[lines.size() - 1 % N];
		else
			previous = lines[(n - 1) % N];

		int laneNumber = 10;
		for (int i = laneNumber; i > 0; i--) {
			if ((short)previous.Y != (short)current.Y) {
				redrawPoly(grass, SCREEN_WIDTH / 2, (short)previous.Y, SCREEN_WIDTH, SCREEN_WIDTH / 2, (short)current.Y, SCREEN_WIDTH);
			}
		}
		//redrawPoly(rumble2, (short)previous.X, (short)previous.Y, (short)(previous.W*1.15), (short)current.X, (short)current.Y, (short)(current.W*1.15));
		redrawPoly(rumble, (short)previous.X, (short)previous.Y, (short)(previous.W*1.03), (short)current.X, (short)current.Y, (short)(current.W*1.03));

		//redrawPoly(currentBiome.roadColor, (short)previous.X, (short)previous.Y, (short)previous.W, (short)current.X, (short)current.Y, (short)current.W);
		redrawPoly(line, (short)previous.X, (short)previous.Y, (short)(previous.W*0.05), (short)current.X, (short)current.Y, (short)(current.W*0.05));
	}

	//Draw Objects and Rivals
	//for (int n = startPos + 199; n >= startPos; n--) {
	//	if (!lines[n%N].atrezzos.empty()) {
	//		for (unsigned int i = 0; i < lines[n%N].atrezzos.size(); i++) {
	//			lines[n%N].DrawObject(lines[n%N].atrezzos[i].first, decoration, lines[n%N].atrezzos[i].second);
	//		}
	//	}
	//	for (unsigned int i = 0; i < rivals.size(); i++) {
	//		if (n%N == (int)rivals[i]->z % N && (int)rivals[i]->z % N > startPos) {
	//			if (rivals[i]->isYellow) {
	//				if (lines[n%N].curve < 0) {
	//					rivals[i]->currentAnimation = &yellowRivalTurnsLeft;
	//				}
	//				else if (lines[n%N].curve > 0) {
	//					rivals[i]->currentAnimation = &yellowRivalTurnsRight;
	//				}
	//				else
	//				{
	//					rivals[i]->currentAnimation = &yellowRivalStraight;
	//				}
	//			}
	//			else {
	//				if (lines[n%N].curve < 0) {
	//					rivals[i]->currentAnimation = &greenRivalTurnsLeft;
	//				}
	//				else if (lines[n%N].curve > 0) {
	//					rivals[i]->currentAnimation = &greenRivalTurnsRight;
	//				}
	//				else
	//				{
	//					rivals[i]->currentAnimation = &greenRivalStraight;
	//				}
	//			}
	//			lines[(int)rivals[i]->z % N].DrawRival(rivals[i], drivers);
	//		}
	//		else if ((int)rivals[i]->z < startPos) {
	//			// If the player overtakes this rival, then teleport the rival
	//			// forward to make him appear again
	//			rivals[i]->z += 200 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (300 - 200)));
	//			// Random e [-0.8f, 0.8f]
	//			rivals[i]->x = -0.8f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0.8f - (-0.8f))));
	//		}
	//	}
	//}


	//for (unsigned int i = 0; i < rivals.size(); i++) {
	//	if (App->player->state != ModulePlayer::PAUSE) {
	//		rivals[i]->z += rivals[i]->speed;
	//		rivals[i]->currentAnimation->speed = 0.2f;
	//	}
	//	else {
	//		rivals[i]->currentAnimation->speed = 0.0f;
	//	}
	//}


	//if (maxy >= MAX_LANDSCAPE_ALTITUDE)
	//{
	//	landscapePositionY = maxy;
	//}
	//else
	//{
	//	landscapePositionY = MAX_LANDSCAPE_ALTITUDE;
	//}
}


