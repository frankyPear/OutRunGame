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
	//Normal Animation
	playerAnimation.frames.push_back({ 208,198,77,40 });
	playerAnimation.frames.push_back({ 300,198,77,40 });

	manAnimation.frames.push_back({ 794,411,21,12 });
	manAnimation.frames.push_back({ 794,425,21,12 });

	womanAnimation.frames.push_back({ 822,411,13,11 });
	womanAnimation.frames.push_back({ 822,423,13,11 });

	//Colision

	playerCrashAnimation.frames.push_back({787 ,155 ,123,40});
	playerCrashAnimation.frames.push_back({787 ,196 ,170,39});
	playerCrashAnimation.frames.push_back({787 ,236 ,166,39});
	playerCrashAnimation.frames.push_back({787 ,276 ,124,40});
	playerCrashAnimation.frames.push_back({1014,155 ,123,40});
	playerCrashAnimation.frames.push_back({ 967 ,196,170,39});
	playerCrashAnimation.frames.push_back({ 971 ,236,166,39});
	playerCrashAnimation.frames.push_back({ 1013,276,124,40});
	//manCrashAnimation;
	//womanCrashAnimation;

	//UpperAnimation Animation

	playerAnimationLeft1.frames.push_back({207,1019,79,40});
	playerAnimationLeft1.frames.push_back({299,1019,79,40});
	playerAnimationLeft2.frames.push_back({206,1140,79,40});
	playerAnimationLeft2.frames.push_back({298,1140,79,40});

	playerAnimationRight1.frames.push_back({ 208,319,79, 40});
	playerAnimationRight1.frames.push_back({300,319,79,40});
	playerAnimationRight2.frames.push_back({208,440 ,79,40});
	playerAnimationRight2.frames.push_back({300,440,79,40});

	//CAR ANIMATIONS
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

	playerAnimation.speed = 0.1f;
	manAnimation.speed = 0.1f;
	womanAnimation.speed = 0.1f;


	//UpperAnimation Animation

	playerAnimationLeft1.speed = 0.1f;
	playerAnimationLeft2.speed = 0.1f;

	playerAnimationRight1.speed = 0.1f;
	playerAnimationRight2.speed = 0.1f;

	playerCrashAnimation.speed = 0.1f;

	//CAR ANIMATIONS
	car1Left.speed = 0.1f;
	car1Left1.speed = 0.1f;
	car1Left2.speed = 0.1f;

	car1Right.speed = 0.1f;
	car1Right1.speed = 0.1f;
	car1Right2.speed = 0.1f;


	car2Left.speed = 0.1f;
	car2Left1.speed = 0.1f;
	car2Left2.speed = 0.1f;

	car2Right.speed = 0.1f;
	car2Right1.speed = 0.1f;
	car2Right2.speed = 0.1f;

	truckLeft.speed = 0.1f;
	truckLeft1.speed = 0.1f;
	truckLeft2.speed = 0.1f;

	truckRight.speed = 0.1f;
	truckRight1.speed = 0.1f;
	truckRight2.speed = 0.1f;
	
}

ModulePlayer::~ModulePlayer()
{
	// Homework : check for memory leaks
}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");
	playerimage = App->textures->Load("Stage\\player.png");
	animations =-1;
	//graphics = App->textures->Load("ryu4.png"); // arcade version

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(playerimage);

	return true;
}

// Update
update_status ModulePlayer::Update()
{
	printPlayer();
	return UPDATE_CONTINUE;
}
void ModulePlayer::printPlayer() {
	switch (animations)
	{
	case 0:
		App->renderer->ScaledBlit(playerimage, (SCREEN_WIDTH / 2) - 124, (SCREEN_HEIGHT - 150), &(App->player->playerAnimation.GetCurrentFrame()), 0.25f, 3, 3);
		App->renderer->ScaledBlit(playerimage, (SCREEN_WIDTH / 2) - 65, (SCREEN_HEIGHT - 150), &(App->player->manAnimation.GetCurrentFrame()), 0.25f, 3, 3);
		App->renderer->ScaledBlit(playerimage, (SCREEN_WIDTH / 2) + 10, (SCREEN_HEIGHT - 149), &(App->player->womanAnimation.GetCurrentFrame()), 0.25f, 3, 3);
		break;
	case 1://lightleft
		App->renderer->ScaledBlit(playerimage, (SCREEN_WIDTH / 2) - 124, (SCREEN_HEIGHT - 150), &(App->player->playerAnimationLeft1.GetCurrentFrame()), 2.85f, 3, 3);
		App->renderer->ScaledBlit(playerimage, (SCREEN_WIDTH / 2) - 65, (SCREEN_HEIGHT - 150), &(App->player->manAnimation.GetCurrentFrame()), 2.85f, 3, 3);
		App->renderer->ScaledBlit(playerimage, (SCREEN_WIDTH / 2) + 5, (SCREEN_HEIGHT - 149), &(App->player->womanAnimation.GetCurrentFrame()), 2.85f, 3, 3);
		break;
	case 2:
		App->renderer->ScaledBlit(playerimage, (SCREEN_WIDTH / 2) - 124, (SCREEN_HEIGHT - 150), &(App->player->playerAnimationLeft2.GetCurrentFrame()), 0.25f, 3, 3);
		App->renderer->ScaledBlit(playerimage, (SCREEN_WIDTH / 2) - 65, (SCREEN_HEIGHT - 150), &(App->player->manAnimation.GetCurrentFrame()), 0.25f, 3, 3);
		App->renderer->ScaledBlit(playerimage, (SCREEN_WIDTH / 2) + 5, (SCREEN_HEIGHT - 149), &(App->player->womanAnimation.GetCurrentFrame()), 0.25f, 3, 3);
		break;
	case 3:
		App->renderer->ScaledBlit(playerimage, (SCREEN_WIDTH / 2) - 124, (SCREEN_HEIGHT - 150), &(App->player->playerAnimationRight1.GetCurrentFrame()), 2.85f, 3, 3);
		App->renderer->ScaledBlit(playerimage, (SCREEN_WIDTH / 2) - 65, (SCREEN_HEIGHT - 150), &(App->player->manAnimation.GetCurrentFrame()), 2.85f, 3, 3);
		App->renderer->ScaledBlit(playerimage, (SCREEN_WIDTH / 2) + 15, (SCREEN_HEIGHT - 149), &(App->player->womanAnimation.GetCurrentFrame()), 2.85f, 3, 3);
		break;
	case 4:
		App->renderer->ScaledBlit(playerimage, (SCREEN_WIDTH / 2) - 124, (SCREEN_HEIGHT - 150), &(App->player->playerAnimationRight2.GetCurrentFrame()), 0.25f, 3, 3);
		App->renderer->ScaledBlit(playerimage, (SCREEN_WIDTH / 2) - 65, (SCREEN_HEIGHT - 150), &(App->player->manAnimation.GetCurrentFrame()), 0.25f, 3, 3);
		App->renderer->ScaledBlit(playerimage, (SCREEN_WIDTH / 2) + 15, (SCREEN_HEIGHT - 149), &(App->player->womanAnimation.GetCurrentFrame()), 0.25f, 3, 3);
		break;
	case 5:
		App->renderer->ScaledBlit(playerimage, (SCREEN_WIDTH / 2) - 124, (SCREEN_HEIGHT - 150), &(App->player->playerCrashAnimation.GetCurrentFrame()), 0.25f, 3, 3);
		
		break;
	default:
		App->renderer->ScaledBlit(playerimage, (SCREEN_WIDTH / 2) - 124, (SCREEN_HEIGHT - 150), &(App->player->playerAnimation.GetCurrentFrame()), 0.25f, 3, 3);
		App->renderer->ScaledBlit(playerimage, (SCREEN_WIDTH / 2) - 65, (SCREEN_HEIGHT - 150), &(App->player->manAnimation.GetCurrentFrame()), 0.25f, 3, 3);
		App->renderer->ScaledBlit(playerimage, (SCREEN_WIDTH / 2) + 10, (SCREEN_HEIGHT - 149), &(App->player->womanAnimation.GetCurrentFrame()), 0.25f, 3, 3);
		break;
	}

}