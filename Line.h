#include <vector>
#include "Globals.h"
using namespace std;

class Line

{
public:

	int segL = 200;
	double camD = 0.84;
	int roadW = 2000;
	float xc, yc, zc;
	float X, Y, W;
	float scale;
	float spriteX;
	float clip;
	int position;
	int elevate;
	//Line() { xc = yc = zc = 0; X = 0; Y = SCREEN_HEIGHT; W = 0; spriteX = 0.f; clip = 0; scale = 0; position = -1; }
	Line() { xc = yc = zc = 0; X = 0; Y = 0; W = 0; spriteX = 0.f; clip = 0; scale = 1; position = -1; elevate = 0; }
	float curve;
	//-->from world to screen
	void projection(int camX, int camY, int camZ) {
		scale = (float)(camD / (zc - camZ));
		X = (1 + scale*(xc - camX)) * SCREEN_WIDTH / 2;
		Y = (1 - scale*(yc - camY)) * SCREEN_HEIGHT /2.5;
		W = scale* roadW * SCREEN_WIDTH / 2;

	}
	void DrawObject(SDL_Rect sp, SDL_Texture* tex, int elevate) {
		float spriteXToDraw = spriteX;
		int w = sp.w;
		int h = sp.h;


		//float destW = w * W / 500;
		//float destH = h * W / 500;

		float destW = w * W / 266;
		float destH = h * W / 266;

		float destX = X + scale * spriteXToDraw * SCREEN_WIDTH / 2;
		float destY = Y + 4;
		destX += destW * spriteXToDraw +3; //offsetX
		//destY += destH *(-1) - 20;    //offsetY ///////JODEEEEER
		destY += destH *(-1);    //offsetY

		float clipH = destY + destH - clip;
		if (clipH<0) clipH = 0;


		destX = X + (W * spriteXToDraw);
		if (clipH >= destH) return;

		sp.h = (int)(h - h*clipH / destH);
		int spriteScaleH = (int)(sp.h*(destH / h));
		int spriteScaleW = (int)(sp.w*(destW / w));
		//App->renderer->Blit(tex, (int)destX - spriteScaleW / 2, (int)destY + 5, &sp, 0.f, spriteScaleW, spriteScaleH);
		//App->renderer->ScaledBlit(tex, (int)destX - spriteScaleW / 2,(int)destY+5, &sp, 0.f, 1.5, 1.5);
		App->renderer->BlitObjects(tex, (int)destX - spriteScaleW / 2,(int)destY, &sp, 0.f, spriteScaleW, spriteScaleH, elevate);
	}
	void DrawCars(SDL_Rect sp, SDL_Texture* tex) {
	
	}
		//int w = sp.w;
		//int h = sp.h;
		//float destX = X + scale * spriteX * SCREEN_WIDTH / 2;
		//float destY = Y + 4;
		//float destW = w * W / 266;
		//float destH = h * W / 266;
		//
		//destX += destW * spriteX; //offsetX
		//destY += destH; // * (-1);    //offsetY
		//
		//float clipH = destY + destH - clip;
		//if (clipH<0) clipH = 0;
		//
		//destX = X +(W * spriteX);
		//if (clipH >= destH) return;
		//
		//sp.h = (int)(h - h*clipH / destH);
		//int spriteScaledH = (int)(sp.h*(destH / h));
		//int spriteScaledW = (int)(sp.w*(destW / w));
		//
		//App->renderer->ScaledBlit(tex, X, destY, &sp, 0.f,1.5,1.5);//, sp.w*(destW / w), sp.h*(destH / h));
		//App->renderer->Blit(playerimage, (SCREEN_WIDTH / 2) - (208 / 2) + 76, (SCREEN_HEIGHT - 80), &(playerAnimation.GetCurrentFrame()), 0.25f);
	//}


};