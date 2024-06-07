#pragma once
#include <iostream>
#include <raylib.h>


class PongBall {
public:
	Sound ballHit;
	Sound ballBounce;
	Sound score;
	Sound scoreTwo;

	float x, y;
	int speedX, speedY;
	static int radius;
	static Color ballColour;
	int playerScore, enemyScore;

	PongBall() = default;

	PongBall(float _x, float _y, int _speedX, int _speedY);

	void Draw();

	void LimitMovement();

	void Update();

	void ResetBall();

};