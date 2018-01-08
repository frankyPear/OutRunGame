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
		X = (float)(1 + scale*(xc - camX)) * SCREEN_WIDTH / 2;
		Y = (float)(1 - scale*(yc - camY)) * SCREEN_HEIGHT /2.5;
		W = scale* roadW * SCREEN_WIDTH / 2;

	}
	
	void DrawFinishCheck(SDL_Rect sp, SDL_Texture* tex, int elevate, int nfinish) {
		float spriteXToDraw = spriteX;
		int w = sp.w;
		int h = sp.h;
		//nfinish = nfinish*(-1);

		float destW = w * W / 266;
		float destH = h * W / 266;

		float destX = X + scale * spriteXToDraw * SCREEN_WIDTH / 2;
		float destY = Y + 4;
		destX += destW * spriteXToDraw + 3; //offsetX
											//destY += destH *(-1) - 20;    //offsetY
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
		App->renderer->BlitObjects(tex, (int)destX - spriteScaleW / 2, (int)destY- nfinish, &sp, 0.f, spriteScaleW, spriteScaleH, elevate);
	}
	void DrawObject(SDL_Rect sp, SDL_Texture* tex, int elevate) {
		float spriteXToDraw = spriteX;
		int w = sp.w;
		int h = sp.h;


		float destW = w * W / 266;
		float destH = h * W / 266;

		float destX = X + scale * spriteXToDraw * SCREEN_WIDTH / 2;
		float destY = Y + 4;
		destX += destW * spriteXToDraw +3; //offsetX
		//destY += destH *(-1) - 20;    //offsetY
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
		float spriteXToDraw = spriteX;
		int w = sp.w;
		int h = sp.h;


		//float destW = w * W / 500;
		//float destH = h * W / 500;

		float destW = w * W / 266;
		float destH = h * W / 266;

		float destX = X + scale * spriteXToDraw * SCREEN_WIDTH / 2;
		float destY = Y + 4;
		destX += destW * spriteXToDraw + 3; //offsetX
											//destY += destH *(-1) - 20;   
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
		App->renderer->BlitObjects(tex, (int)destX - spriteScaleW / 2, (int)destY, &sp, 0.f, spriteScaleW, spriteScaleH, elevate);
	}
};