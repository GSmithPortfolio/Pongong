#include <PongGame.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

int main()
{
	const int screenWidth = 1280;
	const int screenHeight = 800;
	
	bool menuScreen = true;
	bool twoPlayers = false;

	// Initialising Window
	InitWindow(screenWidth, screenHeight, "PingPongPong");
	InitAudioDevice();
	SetTargetFPS(60);

	// Defining background music.
	// Music is "Playin in the Dirt" by Eric Matyas from soundimage.org
	Music bgm = LoadMusicStream("./resources/Quietly-Playin-in-the-Dirt.mp3");

	float timePlayed = 0.0f;
	PlayMusicStream(bgm);

	//Creating game objects.
	PongBall ball(screenWidth / 2, screenHeight / 2, 7, 7);
	PongPaddle player(10, screenHeight / 2 - 60);
	PongEnemy enemy(screenWidth - 25 - 10, screenHeight / 2 - 60, twoPlayers);

	PongGame game(screenHeight, screenWidth, ball, player, enemy);

	// Game Loop.
	while (!WindowShouldClose())
	{
		// Music Handling
		UpdateMusicStream(bgm);
		timePlayed = GetMusicTimePlayed(bgm) / GetMusicTimeLength(bgm);

		// Looping BGM
		if (timePlayed >= 1.0f)
		{
			StopMusicStream(bgm);
			PlayMusicStream(bgm);

			timePlayed = 0.0f;
		}

		// Drawing Main Menu
		if (menuScreen == true)
		{
			BeginDrawing();

			ClearBackground(game.backgroundColour);

			DrawText(TextFormat("PONG GAME"), screenWidth / 2 - 220, 80, 80, WHITE);

			GuiSetStyle(BUTTON, TEXT_ALIGNMENT, TEXT_ALIGN_CENTER);

			//RayGUI handles button drawing and input at once, so the button shape and position are defined in the if statements.
			if (GuiButton(Rectangle{ screenWidth / 2 - 100, screenHeight / 2, 200, 60 }, "One Player"))
			{
				twoPlayers = false;
				menuScreen = false;
			}
			if (GuiButton(Rectangle{ screenWidth / 2 - 100, screenHeight / 2 + 120, 200, 60 }, "Two Player"))
			{
				twoPlayers = true;
				menuScreen = false;
			}

			EndDrawing();
		}
		
		// Play game once a menu button is pressed
		if (menuScreen == false)
		{
			game.Play(twoPlayers);
		}
		
	}

	// Closing everything down
	UnloadMusicStream(bgm);

	CloseAudioDevice();
	CloseWindow();
	return 0;
}