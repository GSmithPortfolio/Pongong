#include <PongEnemy.h>

PongEnemy::PongEnemy(float _x, float _y, bool _twoP) {
	x = _x;
	y = _y;
	twoPlayer = _twoP;
}

// decide whether to allow second player to control the paddle on the right,
// or to have it follow the ball's y position
void PongEnemy::Update(int ball_y) {
	
	if (twoPlayer == false)
	{
		if (y + height / 2 > ball_y)
		{
			y -= speed;
		}
		else
		{
			y += speed;
		}
	}
	if (twoPlayer == true)
	{
		if (IsKeyDown(KEY_UP))
		{
			y -= speed;
		}
		if (IsKeyDown(KEY_DOWN))
		{
			y += speed;
		}
	}

	LimitMovement();
}