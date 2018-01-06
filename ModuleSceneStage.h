#ifndef __MODULESCENESTAGE_H__
#define __MODULESCENESTAGE_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;
struct Rect {
	SDL_Rect rect;
};
struct Cars {
	SDL_Rect cars;
	int hitX = 0;
	int hitXWidth = 0;
	//bool small = false;
	SDL_Rect impactBox;
};

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

	bool TimePlaying();

	//void TimeManager();

	void UserInterface();

	void scenarioBegin();

	void controlVelocity();

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
	SDL_Rect* objectsStage1 = nullptr;


	SDL_Rect markerUITime;
	SDL_Rect markerUIScore;
	SDL_Rect markerUILap;
	SDL_Rect markerUIMap;
	SDL_Rect markerKMh;
	
	//Escenario
	SDL_Rect gradas;
	int gradapos;
	SDL_Rect palmatreeSmall;
	int ptspos;
	SDL_Rect palmatreeBig;
	int ptbpos;
	Animation ocean;
	int oceanpos;
	int oceanpos2;
	//SDL_Rect rightPanel;
	int rppos;
	//SDL_Rect leftPanel;
	int lppos;
	SDL_Rect start;
	int sfpos;
	//SDL_Rect finish;
	int ffpos;
	//SDL_Rect house1;
	int h1pos;
	//SDL_Rect house2;
	int h2pos;
	//SDL_Rect check;
	Animation trafficLight;
	int tlpos;
	SDL_Rect surfer;
	int surpos;
	SDL_Rect flag;
	int flagpos;
	//SDL_Rect people1;
	int peopos1;
	//SDL_Rect people2;
	int peopos2;
	//SDL_Rect harrow;
	int harrowpos;
	//SDL_Rect Ocean1;
	int ocean1;
	//
	int countSequence = -1;
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

	unsigned int music2;
	int position = 0;
	bool downOk = false;
	bool iteration = false;
	long initTimer;
	const int ColourRoad1[4] = { 107, 107, 107, 255 };
	const int ColourRoad2[4] = { 105, 105, 105, 255 };
	int N = 0;
	int pos;
	int auxPos;
	int playerX;
	int playerY;
	int seg_pos;
	const float MAX_LANDSCAPE_ALTITUDE = 273.0f;
	float landscapePositionX = 0.0f;
	float landscapePositionY = 0.0f;
	float foregroundPositionX = 0.0f;
	int landscapeParallaxFactor = 300;
	int foregroundParallaxFactor = 200;
	int score;
private:
	int maxPuntuation;
	int stage;
	float time;
	float lastValue;
	int speed;
	float modAlture = 0.0f;
	float currentAlture = 0.0f;
	bool HiVelocity;
	int vel;
	std::vector<Rect*> Rects;
	std::vector<Cars*> Cars;
	//clock_t initTime = clock();
private:
	//clock_t initTime;

};

#endif // __MODULESCENETAGE_H__