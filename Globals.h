#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include "SDL/include/SDL_rect.h"

#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__);
// Configuration -----------
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define SCREEN_SIZE 1
#define FULLSCREEN false
#define VSYNC true
#define TITLE "Outrun Game"
#define PINKFONT "pinkFonts"
#define GREENFONT "greenfonts"
#define LIGHTGREENFONT "lightgreenfonts"
#define PURPLEFONT "purplefonts"
#define FONTPATHPINK "Fonts\\pinkfont.bmp"
#define FONTPATHGREEN "Fonts\\greenfont.bmp"
#define FONTPATHGREENLIGHT "Fonts\\lightgreenfont.bmp"
#define FONTPATHPURPLE "Fonts\\purplefont.bmp"
#define FONTPATHYELLOW "Fonts\\yellowfont.bmp"
#define MARKERPATH "Fonts\\marker.png"
#define VELOCITYPATH "Fonts\\velocity.png"
#define INTROPATH "Background\\OutRunIntro.png"
#define LOGOPATH "Background\\OutRun.png"
#define SEGAPATH "Fonts\\SEGA.png"
#define FONTMASK "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890.:Ç"
#define NUMBERMASK "0123456789"
#define MAGICALPATH "Background\\OutRunMagical.bmp"
#define BREEZEPATH "Background\\OutRunBreeze.bmp"
#define WAVEPATH "Background\\OutRunWave.bmp"
#define BEATPATH "Background\\OutRunBeat.bmp"
#define SOUNDMAGICALPATH "Sound\\01 - Magical - Sound - Shower.ogg"
#define SOUNDBREEZEPATH "Sound\\02-Passing-Breeze.ogg"
#define SOUNDWAVEPATH "Sound\\03-Splash-Wave.ogg"
#define SOUNDLASTWAVEPATH "Sound\\04-Last-Wave.ogg"
#define SOUNDBEATPATH "Sound\\05-Step-on-Beat"
#define INPUTLEFT App->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT
#define INPUTRIGHT App->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT
#define SECONDSPASSED (clock() - initTimer) / CLOCKS_PER_SEC
#define BACKGROUND "Background\\OutRunBackground1.png"
#define STAGE "Stage\\Stage1.png"
#define FRAMES_PER_SECOND 60
#define NOTCURVE 0
#define LOWCURVELEFT -2
#define HIGHCURVELEFT -4
#define LOWCURVERIGHT 2
#define HIGHCURVERIGHT 2
#define ROAD1 RGBA(107, 107, 107, 255);
#define ROAD2 RGBA(128, 128, 128, 255);
#define BLANK RGBA(255,255,255,255);
#define RED RGBA(255,0,0,255);
#define BEACH1 RGBA(222, 200, 131, 255);

void log(const char file[], int line, const char* format, ...);

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};

// Deletes a buffer
#define RELEASE( x ) \
    {\
       if( x != nullptr )\
       {\
         delete x;\
	     x = nullptr;\
       }\
    }

// Deletes an array of buffers
#define RELEASE_ARRAY( x ) \
	{\
       if( x != nullptr )\
       {\
           delete[] x;\
	       x = nullptr;\
		 }\
	 }


struct RGBA {
	int r;
	int g;
	int b;
	int a;
	RGBA() { r = 0; g = 0; b = 0; a = 0; }
	RGBA(int red, int green, int blue, int alpha) {
		r = red, g = green, b = blue, a = alpha;
	}
};
#endif //__GLOBALS_H__