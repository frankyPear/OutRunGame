#include <vector>
#include "Globals.h"
using namespace std;

class Line

{
public:

	int segL = 200;
	float camD = 0.84;
	int roadW = 2000;
	float xc, yc, zc;
	float X, Y, W;
	float scale;
	float spriteX;
	float clip;
	Line() { xc = yc = zc = 0; X = 0; Y = SCREEN_HEIGHT; W = 0; spriteX = -1; clip = 0; scale = 0; }

	float curve;
	//-->from world to screen
	void projection(int camX, int camY, int camZ) {
		scale = camD / (zc - camZ);
		X = (1 + scale*(xc - camX)) * SCREEN_WIDTH / 2;
		Y = (1 - scale*(yc - camY)) * SCREEN_HEIGHT /2;
		W = scale* roadW * SCREEN_WIDTH / 2;

	}
	void DrawObject(SDL_Rect sp, SDL_Texture* tex) {
		int w = sp.w;
		int h = sp.h;
		float destX = X + scale * spriteX * SCREEN_WIDTH / 2;
		float destY = Y + 4;
		float destW = w * W / 266;
		float destH = h * W / 266;

		destX += destW * spriteX; //offsetX
		destY += destH * (-1);    //offsetY

		float clipH = destY + destH - clip;
		if (clipH<0) clipH = 0;

		X += (W * spriteX);
		if (clipH >= destH) return;

		sp.h = h - h*clipH / destH;
		//App->renderer->Blit(tex, X, destY, &sp, 0.f, sp.w*(destW / w), sprite.h*(destH / h));

	}


};