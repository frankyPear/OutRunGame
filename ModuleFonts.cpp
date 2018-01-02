#include "Globals.h"
#include "Application.h"
#include "ModuleFonts.h"
#include "ModuleWindow.h"
#include "SDL/include/SDL.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"

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
	pinkFonts = App->textures->Load(FONTPATHPINK);
	greenFonts = App->textures->Load(FONTPATHGREEN);
	lightgreenFonts = App->textures->Load(FONTPATHGREENLIGHT);
	purpleFonts = App->textures->Load(FONTPATHPURPLE);
	yellowFonts = App->textures->Load(FONTPATHYELLOW);
	velocity = App->textures->Load(VELOCITYPATH);
	marker = App->textures->Load(MARKERPATH);

	return true;
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
			pos.w = 17;// *count;
			pos.h = 15;
			return pos;
		}
		else {
			count++;		
		}
	}
	return pos;
}

SDL_Rect ModuleFonts::FindNumber(char characterToFind) {
	string CharacterMask = NUMBERMASK;
	SDL_Rect* Fontposition;
	SDL_Rect pos = { 0,0,0,0 };
	int count = 0;
	for each (char c in CharacterMask)
	{
		if (c == characterToFind) {
			switch (c)
			{
			case '0':
				pos.x = 0;
				pos.y = 1;
				pos.w = 33;
				pos.h = 57;
				break;
			case '1':
				pos.x = 37;
				pos.y = 1;
				pos.w = 10;
				pos.h = 57;
				break;
			case '2':
				pos.x = 50;
				pos.y = 1;
				pos.w = 33;
				pos.h = 57;
				break;
			case '3':
				pos.x = 87;
				pos.y = 1;
				pos.w = 33;
				pos.h = 57;
				break;
			case '4':
				pos.x = 123;
				pos.y = 1;
				pos.w = 33;
				pos.h = 57;
				break;
			case '5':
				pos.x = 159;
				pos.y = 1;
				pos.w = 33;
				pos.h = 57;
				break;
			case '6':
				pos.x = 196;
				pos.y = 1;
				pos.w = 33;
				pos.h = 57;
				break;
			case '7':
				pos.x = 233;
				pos.y = 1;
				pos.w = 33;
				pos.h = 57;
				break;
			case '8':
				pos.x = 270;
				pos.y = 1;
				pos.w = 33;
				pos.h = 57;
				break;
			case '9':
				pos.x = 305;
				pos.y = 1;
				pos.w = 33;
				pos.h = 57;
				break;
			default:
				pos.x = 0;
				pos.y = 1;
				pos.w = 33;
				pos.h = 57;
				break;
			}
			return pos;
		}
		//if (c == characterToFind) {

		//}
		//else {
		//	count++;
		//}
	}
	return pos;
}
void ModuleFonts::PrintInterface(SDL_Texture* font, int positionX, int positionY, string textToPrint) {
	SDL_Texture* fontToPrint = font;
	SDL_Rect printRect;
	printRect.x = positionX;
	printRect.y = positionY;

	for each (char character in textToPrint)
	{
		SDL_Rect charPointer = FindCharacter(character);

		if (&charPointer != nullptr) {
			printRect.h = charPointer.h;
			printRect.w = charPointer.w;
			if (character == ':')printRect.y -= 5;
			if (SDL_RenderCopy(App->renderer->renderer, fontToPrint, &charPointer, &printRect) != 0)
			{
				LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
			}
			printRect.y = positionY;
			printRect.x += 17;
		}
	}
}

void ModuleFonts::PrintCharacter(SDL_Texture* font, int positionX, int positionY, string textToPrint) {
	SDL_Texture* fontToPrint = font;
	SDL_Rect printRect;
	printRect.x = positionX;
	printRect.y = positionY;

	for each (char character in textToPrint)
	{
		SDL_Rect charPointer = FindCharacter(character);

		if (&charPointer != nullptr) {
			printRect.h = charPointer.h;
			printRect.w = charPointer.w;
			if (character == ':')printRect.y -= 5;
			if (SDL_RenderCopy(App->renderer->renderer, fontToPrint, &charPointer, &printRect) != 0)
			{
				LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
			}
			printRect.y = positionY;
			printRect.x += 17;
		}
	}
}
void ModuleFonts::PrintVelocity(SDL_Texture* font, int positionX, int positionY, string textToPrint) {
	SDL_Texture* fontToPrint = font;
	SDL_Rect printRect;
	printRect.x = positionX;
	printRect.y = positionY;

	for each (char character in textToPrint)
	{
		SDL_Rect charPointer = FindNumber(character);

		if (&charPointer != nullptr) {
			printRect.h = charPointer.h;
			printRect.w = charPointer.w;
			//if (character == ':')printRect.y -= 5;
			if (SDL_RenderCopy(App->renderer->renderer, fontToPrint, &charPointer, &printRect) != 0)
			{
				LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
			}
			printRect.y = positionY;
			printRect.x += 35;
		}
	}
}