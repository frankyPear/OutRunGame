#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include "SDL/include/SDL_rect.h"

#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__);

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

// Configuration -----------
//#define SCREEN_WIDTH 384
//#define SCREEN_HEIGHT 224
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_SIZE 1
#define FULLSCREEN false
#define VSYNC true
#define TITLE "Outrun Game"
#define PINKFONT "pinkFonts"
#define GREENFONT "greenfonts"
#define LIGHTGREENFONT "lightgreenfonts"
#define PURPLEFONT "purplefonts"
#define FONTPATHPINK "Fonts\\pinkfont.png"
#define FONTPATHGREEN "Fonts\\greenfonts.png"
#define FONTPATHGREENLIGHT "Fonts\\lightgreenfonts.png"
#define FONTPATHPURPLE "Fonts\\purplefonts.png"
#define FONTMASK "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789.·Ç"

#endif //__GLOBALS_H__