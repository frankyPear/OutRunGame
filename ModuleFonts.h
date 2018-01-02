#ifndef __MODULEFONTS_H__
#define __MODULEFONTS_H__

#include <vector>
#include "Module.h"
#include <map>
#include <string>

#define DEFAULT_MUSIC_FADE_TIME 2.0f
struct SDL_Texture;
struct SDL_Surface;
using namespace std;
class ModuleFonts : public Module
{
public:

	ModuleFonts(bool start_enabled = true);
	~ModuleFonts();

	bool Init();
	bool LoadFonts();
	bool CleanUp();

	SDL_Rect FindCharacter(char characterToFind);

	SDL_Rect FindNumber(char characterToFind);

	void PrintInterface(SDL_Texture * font, int positionX, int positionY, string textToPrint);

	void PrintCharacter(SDL_Texture * font, int positionX, int positionY, string textToPrint);

	void PrintVelocity(SDL_Texture * font, int positionX, int positionY, string textToPrint);

	SDL_Texture* pinkFonts = nullptr;
	SDL_Texture* greenFonts = nullptr;
	SDL_Texture* lightgreenFonts = nullptr;
	SDL_Texture* purpleFonts = nullptr;
	SDL_Texture* yellowFonts = nullptr;
	SDL_Texture* velocity = nullptr;
	SDL_Texture* marker = nullptr;


private:

};

#endif // __MODULEFONTS_H__