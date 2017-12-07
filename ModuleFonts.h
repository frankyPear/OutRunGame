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

	void PrintCharacter(SDL_Surface * font, int positionX, int positionY, string textToPrint);

	//void PrintCharacter(SDL_Surface * font, int positionX, int positionY, string textToPrint);

	// Print Fonts
	SDL_Surface* pinkFonts = nullptr;
	SDL_Surface* greenFonts = nullptr;
	SDL_Surface* lightgreenFonts = nullptr;
	SDL_Surface* purpleFonts = nullptr;


private:

};

#endif // __MODULEFONTS_H__