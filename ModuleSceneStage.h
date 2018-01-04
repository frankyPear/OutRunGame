#ifndef __MODULESCENESTAGE_H__
#define __MODULESCENESTAGE_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneStage : public Module
{
public:
	ModuleSceneStage(bool start_enabled = true);
	~ModuleSceneStage();

	bool Start();
	update_status Update();

	bool redrawPoly(RGBA c, short x1, short y1, short w1, short x2, short y2, short w2);

	bool redrawPoly2(RGBA c, short x1, short y1, short w1, short x2, short y2, short w2);

	void reDrawRoad();

	void ChangeAltitude(float & altitudeVariation, float targetVariation, int currentSegment, int startingSegment, int endSegment, int heldSegments);

	void TimeManager();

	void UserInterface();

	void scenarioBegin();

	//bool reDraw(int red, int green, int blue, int alpha, float lineWorldX, float lineWorldY, float lineWorldW, float lineScreenX, float lineScreenY, float lineScreenZ);
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* landscape = nullptr;
	SDL_Texture* playerimage = nullptr;
	SDL_Texture* road = nullptr;
	SDL_Rect ground;
	SDL_Rect background;



	//
	SDL_Texture* Uinterface = nullptr;
	SDL_Texture* Stage1 = nullptr;

	SDL_Rect markerUITime;
	SDL_Rect markerUIScore;
	SDL_Rect markerUILap;
	SDL_Rect markerUIMap;
	SDL_Rect markerKMh;
	
	//Escenario
	SDL_Rect gradas;
	SDL_Rect palmatreeSmall;
	SDL_Rect palmatreeBig;
	Animation ocean;
	SDL_Rect rightPanel;
	SDL_Rect leftPanel;
	SDL_Rect start;
	SDL_Rect finish;
	SDL_Rect house1;
	SDL_Rect house2;
	//SDL_Rect check;
	Animation trafficLight;
	SDL_Rect surfer;
	Animation flag;
	SDL_Rect people1;
	SDL_Rect people2;
	SDL_Rect harrow;
	//
	int minuteLap;

	int secondsPassed;
	int secondsToQuit;
	int secondsLap;
	int secondsAux;

	int countCurve = 0;

	int miliSecondsLap;

	double second_since_start;
	unsigned msSecondsPassed;
	time_t startTime;
	int secondsRealTime;


	Animation logo;
	Animation playerAnimation;
	Animation manAnimation;
	Animation womanAnimation;
	unsigned int music2;
	int position = 0;
	bool downOk = false;
	bool iteration = false;
	long initTimer;
	const int ColourRoad1[4] = { 107, 107, 107, 255 };
	const int ColourRoad2[4] = { 105, 105, 105, 255 };
	int N = 0;
	int pos;
	int playerX;
	int seg_pos;
	const float MAX_LANDSCAPE_ALTITUDE = 273.0f;
	float landscapePositionX = 0.0f;
	float landscapePositionY = 0.0f;
	float foregroundPositionX = 0.0f;
	int landscapeParallaxFactor = 300;
	int foregroundParallaxFactor = 200;
private:
	int maxPuntuation;
	int stage;
	float time;
	int score;
	int speed;
	float modAlture = 0.0f;
	float currentAlture = 0.0f;


	//filledPolygonRGBA(App->renderer->renderer, x, y, 4, 128, 128, 128, 255);
	//107 *3  O 105*3 ROAD
//	filledPolygonRGBA(App->renderer->renderer, x2, y, 4, 192, 192, 160, 255);
//}
//filledPolygonRGBA(App->renderer->renderer, x3, y, 4, 255, 0, 0, 255);
//blank for lines filledPolygonRGBA(App->renderer->renderer, x, y, 4, 225, 225, 225, 255);
//GREEN 1 filledPolygonRGBA(App->renderer->renderer, x, y, 4, 255, 255, 255, 155);
//RED 255,0,0,255
//filledPolygonRGBA(App->renderer->renderer, x, y, 4, 254, 233, 148, 155);
//filledPolygonRGBA(App->renderer->renderer, x, y, 4, 254, 243, 201, 155);
//filledPolygonRGBA(App->renderer->renderer, x, y, 4, 236, 226, 198, 155);
//filledPolygonRGBA(App->renderer->renderer, x, y, 4, 245, 222, 179, 155);
//filledPolygonRGBA(App->renderer->renderer, x, y, 4, 253, 224, 170, 155);
//128, 128, 128, 255
//225, 225, 225, 255
//192, 192, 160, 255
//255, 255, 255, 255

	//std::vector<Line> lines;
	//clock_t initTime = clock();
private:
	//clock_t initTime;

};

#endif // __MODULESCENETAGE_H__