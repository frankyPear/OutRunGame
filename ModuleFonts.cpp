#include "Globals.h"
#include "Application.h"
#include "ModuleFonts.h"
#include "ModuleWindow.h"
#include "SDL/include/SDL.h"

using namespace std;

ModuleFonts::ModuleFonts(bool start_enabled) : Module(start_enabled)
{}

// Destructor
ModuleFonts::~ModuleFonts()
{}

// Called before render is available
bool ModuleFonts::Init()
{
	LOG("Loading Fonts");
	


	bool ret = true;

	// load support for the OGG format
	//int flags = MIX_INIT_OGG;
	//int init = Mix_Init(flags);
	//
	if(!LoadFonts())
	{
		ret = false;
	}
	else {
		LOG("Loading Fonts");
		ret = true;
	}
	return ret;
}
// Called before render is available
bool ModuleFonts::LoadFonts()
{
	LOG("Loading Fonts");
// 	pinkFonts = SDL_LoadBMP("Fonts\\pinkfont.png");
//	greenFonts = SDL_LoadBMP("Fonts\\greenfonts.png");
//	lightgreenFonts = SDL_LoadBMP("Fonts\\lightgreenfonts.png");
//	purpleFonts = SDL_LoadBMP("Fonts\\purplefonts.png");
	pinkFonts = SDL_LoadBMP(FONTPATHPINK);
	pinkFonts = SDL_LoadBMP(FONTPATHGREEN);
	pinkFonts = SDL_LoadBMP(FONTPATHGREENLIGHT);
	purpleFonts = SDL_LoadBMP(FONTPATHPURPLE);
	bool ret = true;

	
	//ret = App->fonts->Init();

	return ret;
}
// Called before quitting
bool ModuleFonts::CleanUp()
{
	LOG("Free fonts");

	return true;
}

SDL_Rect ModuleFonts::FindCharacter(char characterToFind) {
	string CharacterMask = FONTMASK;
	SDL_Rect* Fontposition;
	SDL_Rect pos = { 0,0,0,0};
	int count = 0;
	for each (char c in CharacterMask)
	{
		if (c == characterToFind) {
			pos.x = 17 * count;
			pos.y = 0;
			pos.w = 17 * count;
			pos.h = 15;
			return pos;
		}
		else {
			count++;
			//Fontposition->x = Fontposition->x +16;
			//Fontposition->y = 0;
			//Fontposition->w = Fontposition->w + 16;
			//Fontposition->h = Fontposition->h + 15;			
		}
	}
	return pos;
}

void ModuleFonts::PrintCharacter(SDL_Surface* font, int positionX, int positionY, string textToPrint) {
	SDL_Surface* fontToPrint = font;
	SDL_Rect printRect;
	printRect.x = positionX;
	printRect.y = positionY;
	for each (char character in textToPrint)
	{
		SDL_Rect charPointer = FindCharacter(character);
		if (&charPointer != nullptr) {
			printRect.h = charPointer.h;
			printRect.w = charPointer.w;
			SDL_BlitSurface(fontToPrint, &charPointer, SDL_GetWindowSurface(App->window->window), &printRect);
			printRect.x += charPointer.x;
		}
	}
}


