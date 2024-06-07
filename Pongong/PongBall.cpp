#include <PongBall.h>

// setting static variables
int PongBall::radius = 20;
Color PongBall::ballColour = Color{ 102, 153, 153, 255 };

PongBall::PongBall(float _x, float _y, int _speedX, int _speedY) {
	x = _x;
	y = _y;
	speedX = _speedX;
	speedY = _speedY;
	playerScore = 0;
	enemyScore = 0;

	// loading sound effects
	//Sound effects made online using jsfxr at sfxr.me
	ballHit = LoadSound("./resources/ballHit.wav");
	ballBounce = LoadSound("./resources/ballBounce.wav");
	score = LoadSound("./resources/score.wav");
	scoreTwo = LoadSound("./resources/scoreTwo.wav");
}

void PongBall::Draw() {
	DrawCircle(x, y, radius, ballColour);
}

/* detect whether the ball hits the sides of the window
if the top/bottom, reverse the velocity and play the bounce sound
if through the left/right, increase the relevant score, play the scoring sound and reset the ball*/
void PongBall::LimitMovement() {
	if (y + radius >= GetScreenHeight() || y - radius <= 0)
	{
		speedY *= -1;
		PlaySound(ballBounce);
	}

	if (x + radius >= GetScreenWidth())
	{
		playerScore++;
		PlaySound(score);
		ResetBall();
	}

	if (x - radius <= 0)
	{
		enemyScore++;
		PlaySound(scoreTwo);
		ResetBall();
	}
}

// update the ball's x and y positions
void PongBall::Update() {
	x += speedX;
	y += speedY;

	LimitMovement();
}

// reset the ball to the center and choose a random direction after scoring
void PongBall::ResetBall() {
	x = GetScreenWidth() / 2;
	y = GetScreenHeight() / 2;

	int speedChoices[2] = { -1,1 };
	speedX *= speedChoices[GetRandomValue(0, 1)];
	speedY *= speedChoices[GetRandomValue(0, 1)];
}