#include <PongGame.h>
#include <raygui.h>

// setting static variables
Color PongGame::backgroundColour = Color{ 6, 21, 57, 255 };
Color PongGame::bgOne = Color{ 46,  65, 114, 255 };
Color PongGame::bgTwo = Color{ 79, 98, 142, 255 };

PongGame::PongGame(int _screenH, int _screenW, PongBall _ball, PongPaddle _player, PongEnemy _enemy) {
	screenH = _screenH;
	screenW = _screenW;

	ball = _ball;
	player = _player;
	enemy = _enemy;
}

// main game loop code
void PongGame::Play(bool _twoP) {
	enemy.twoPlayer = _twoP;
	
	BeginDrawing();

	// update objects
	ball.Update();
	player.Update();
	enemy.Update(ball.y);

	// check if the ball bounces off of the player or enemy rectangles, bounce and play a sound
	if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, Rectangle{ player.x, player.y, player.width, player.height }))
	{
		ball.speedX *= -1;
		PlaySound(ball.ballHit);
	}

	if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, Rectangle{ enemy.x, enemy.y, enemy.width, enemy.height }))
	{
		ball.speedX *= -1;
		PlaySound(ball.ballHit);
	}

	// draw background elements
	ClearBackground(backgroundColour);
	DrawRectangle(screenW / 2, 0, screenW / 2, screenH, bgOne);
	DrawCircle(screenW / 2, screenH / 2, 150, bgTwo);
	DrawLine(screenW / 2, 0, screenW / 2, screenH, WHITE);

	DrawText(TextFormat("%i", ball.playerScore), screenW / 4 - 20, 20, 80, WHITE);
	DrawText(TextFormat("%i", ball.enemyScore), 3 * screenW / 4 - 20, 20, 80, WHITE);


	// draw game objects
	ball.Draw();
	enemy.Draw();
	player.Draw();

	EndDrawing();
}