#pragma once
#include <iostream>
#include <raylib.h>

class PongPaddle {
public:
	float x, y;
	static float width, height;
	static int speed;

	PongPaddle() = default;

	PongPaddle(float _x, float _y);

	void Draw();

	void LimitMovement();

	void Update();
};