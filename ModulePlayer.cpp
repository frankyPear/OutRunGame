#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "SDL/include/SDL.h"

ModulePlayer::ModulePlayer(bool start_enabled) : Module(start_enabled)
{
	position.x = 100;
	position.y = 216;

	// idle animation (arcade sprite sheet)
	idle.frames.push_back({7, 14, 60, 90});
	idle.frames.push_back({95, 15, 60, 89});
	idle.frames.push_back({184, 14, 60, 90});
	idle.frames.push_back({276, 11, 60, 93});
	idle.frames.push_back({366, 12, 60, 92});
	idle.speed = 0.2f;
	
	// walk backward animation (arcade sprite sheet)
	backward.frames.push_back({542, 131, 61, 87});
	backward.frames.push_back({628, 129, 59, 90});
	backward.frames.push_back({713, 128, 57, 90});
	backward.frames.push_back({797, 127, 57, 90});
	backward.frames.push_back({883, 128, 58, 91});
	backward.frames.push_back({974, 129, 57, 89});
	backward.speed = 0.1f;

	// TODO 8: setup the walk forward animation from ryu4.png
	//if (!directionleft) {
		ryu.frames.push_back({ 8, 126,    54, 94 });
		ryu.frames.push_back({ 77, 126,   61, 94 });
		ryu.frames.push_back({ 161, 126,  65, 94 });
		ryu.frames.push_back({ 258, 126,  64, 94 });
		ryu.frames.push_back({ 351, 126,  55, 94 });
		ryu.frames.push_back({ 431, 126,  51, 94 });
		ryu.speed = 0.1f;


}

ModulePlayer::~ModulePlayer()
{
	// Homework : check for memory leaks
}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->textures->Load("ryu4.png"); // arcade version

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
	// TODO 9: Draw the player with its animation
	// make sure to detect player movement and change its
	// position while cycling the animation(check Animation.h)
	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT){
		directionleft = true;
		App->renderer->Blit(graphics, 193, 109, &(backward.GetCurrentFrame()), 0.10f);
	}
	else if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT) {
		//directionleft = false;
		App->renderer->Blit(graphics, 193, 109, &(ryu.GetCurrentFrame()), 0.10f);
	}
	else {
		App->renderer->Blit(graphics, 193, 109, &(idle.GetCurrentFrame()), 0.10f);
	}

	//IF PLAYER IDLE EN REPOS ETC ETC
	return UPDATE_CONTINUE;
}