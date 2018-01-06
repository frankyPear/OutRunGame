#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleSceneStage.h"
#include "SDL/include/SDL.h"

ModulePlayer::ModulePlayer(bool start_enabled) : Module(start_enabled)
{
	position.x = 100;
	position.y = 216;

	playerAnimation.frames.push_back({ 208,198,77,40 });
	playerAnimation.frames.push_back({ 300,198,77,40 });

	manAnimation.frames.push_back({ 794,411,21,12 });
	manAnimation.frames.push_back({ 794,425,21,12 });

	womanAnimation.frames.push_back({ 822,411,13,11 });
	womanAnimation.frames.push_back({ 822,423,13,11 });

	car1Left.frames.push_back({30,7,39,30});
	car1Left.frames.push_back({ 92,7,39,30});
	car1Left1.frames.push_back({29,64,50,30});
	car1Left1.frames.push_back({91,64,50,30});
	car1Left2.frames.push_back({29,121,57,30});
	car1Left2.frames.push_back({91,121,57,30 });

	car1Right.frames.push_back({424,7,39,30});
	car1Right.frames.push_back({ 486,7,39,30 });
	car1Right1.frames.push_back({414,64,50,30});
	car1Right1.frames.push_back({476,64,50,30 });
	car1Right2.frames.push_back({407,121,57,30});
	car1Right2.frames.push_back({469,121,57,30 });


	car2Left.frames.push_back({30,178,39,34});
	car2Left.frames.push_back({ 92,178,39,34 });
	car2Left1.frames.push_back({31,244,44, 34});
	car2Left1.frames.push_back({ 93,244,44,34 });
	car2Left2.frames.push_back({28,310 ,51,34});
	car2Left2.frames.push_back({ 90,310,51,34 });

	car2Right.frames.push_back({424,178,39,34});
	car2Right.frames.push_back({  486 ,178,39,34 });
	car2Right1.frames.push_back({418,244,44,34});
	car2Right1.frames.push_back({ 480,244,44,34 });
	car2Right2.frames.push_back({414,310,51,34});
	car2Right2.frames.push_back({ 476,310,51,34 });

	truckLeft  .frames.push_back({156,14,42,53});
	truckLeft.frames.push_back({ 215,13,42, 53});
	truckLeft1 .frames.push_back({157,118,48,53});
	truckLeft1.frames.push_back({ 216,117,48,53 });
	truckLeft2 .frames.push_back({157,222,54,});
	truckLeft2.frames.push_back({216,221,54, });

	truckRight .frames.push_back({ 298,14,42 ,53});
	truckRight.frames.push_back({  357,13,42 ,53 });
	truckRight1.frames.push_back({ 291,118,48,53});
	truckRight1.frames.push_back({ 350,117,48,53 });
	truckRight2.frames.push_back({ 283,222,54,54});
	truckRight2.frames.push_back({ 344,221,54,54 });
	// TODO 8: setup the walk forward animation from ryu4.png
	//if (!directionleft) {
		//ryu.frames.push_back({ 8, 126,    54, 94 });
		//ryu.frames.push_back({ 77, 126,   61, 94 });
		//ryu.frames.push_back({ 161, 126,  65, 94 });
		//ryu.frames.push_back({ 258, 126,  64, 94 });
		//ryu.frames.push_back({ 351, 126,  55, 94 });
		//ryu.frames.push_back({ 431, 126,  51, 94 });
		//ryu.speed = 0.1f;


}

ModulePlayer::~ModulePlayer()
{
	// Homework : check for memory leaks
}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	//graphics = App->textures->Load("ryu4.png"); // arcade version

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	return true;
}

// Update
update_status ModulePlayer::Update()
{
	//if (App->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	//{
	//	App->scene_stage->pos += 200;
	//	App->scene_stage->score += 20;
	//}
	//if (App->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	//{
	//	playerY -= 85;
	//}
	//
	//if (App->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	//{
	//	playerY += 85;
	//}

	//// TODO 9: Draw the player with its animation
	//// make sure to detect player movement and change its
	//// position while cycling the animation(check Animation.h)
	//if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT){
	//	directionleft = true;
	//	App->renderer->Blit(graphics, 193, 109, &(backward.GetCurrentFrame()), 0.10f);
	//}
	//else if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT) {
	//	//directionleft = false;
	//	playerX += 200;
	//}
	//else {
	//	App->renderer->Blit(graphics, 193, 109, &(idle.GetCurrentFrame()), 0.10f);
	//}

	//IF PLAYER IDLE EN REPOS ETC ETC
	return UPDATE_CONTINUE;
}