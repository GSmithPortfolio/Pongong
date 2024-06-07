#pragma once
#include <PongPaddle.h>

class PongEnemy : public PongPaddle {
public:
	bool twoPlayer = false;

	PongEnemy() = default;

	PongEnemy(float _x, float _y, bool _twoP);

	void Update(int ball_y);
};