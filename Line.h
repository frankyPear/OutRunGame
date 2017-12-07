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
	Line() { xc = yc = zc = 0; }
	//-->from world to screen
	void projection(int camX, int camY, int camZ) {
		scale = camD / (zc - camZ);
		X = (1 + scale*(xc - camX)) * SCREEN_WIDTH / 2;
		Y = (1 + scale*(xc - camX)) * SCREEN_HEIGHT / 2;
		W = scale* roadW * SCREEN_WIDTH / 2;

	}
};