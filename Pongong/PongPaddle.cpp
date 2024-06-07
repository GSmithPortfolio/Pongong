#include <PongPaddle.h>

// setting static variables
float PongPaddle::width = 25;
float PongPaddle::height = 120;
int PongPaddle::speed = 7;

PongPaddle::PongPaddle(float _x, float _y) {
	x = _x;
	y = _y;
}

void PongPaddle::Draw() {
	DrawRectangleRounded(Rectangle{ x, y, width, height }, 0.4, 0, WHITE);
}

// Stop paddle from moving off of the screen
void PongPaddle::LimitMovement() {
	if (y <= 0)
	{
		y = 0;
	}
	if (y + height >= GetScreenHeight())
	{
		y = GetScreenHeight() - height;
	}
}

// read paddle inputs and update position
void PongPaddle::Update() {
	if (IsKeyDown(KEY_W))
	{
		y -= speed;
	}
	if (IsKeyDown(KEY_S))
	{
		y += speed;
	}

	LimitMovement();
}