#pragma once
#include <iostream>
#include <raylib.h>
#include <PongBall.h>
#include <PongPaddle.h>
#include <PongEnemy.h>

class PongGame
{
public:
	bool twoPlay = false;
	PongBall ball;
	PongPaddle player;
	PongEnemy  enemy;

	int screenH, screenW;

	static Color backgroundColour;
	static Color bgOne;
	static Color bgTwo;

	PongGame(int _screenH, int _screenW, PongBall _ball, PongPaddle _player, PongEnemy _enemy);

	void Play(bool _twoP);
};
