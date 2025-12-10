#include "Car.h"
#include <DxLib.h>
#include "globals.h"

namespace {
	const int CAR_W = 50;
	const int CAR_H = 25;
}

Car::Car()
	:BaseChara(), w_(CAR_W), h_(CAR_H)
{
}

Car::Car(const Vector2D& pos, const Vector2D& vel, unsigned int color)
	:BaseChara(pos, vel, color, SHAPE::RECTANGLE), w_(CAR_W), h_(CAR_H)
{
}

Car::~Car()
{
}

void Car::Update()
{
	RepeatMoveLeftRight();
}

void Car::Draw()
{
	const Vector2D& pos = GetPos();
	SetPos(Vector2D(pos.x, (float)GROUND_HEIGTH - CAR_H));
	//pos‚ð¶ã‚Æ‚µ‚ÄA50x25‚Ì’·•ûŒ`‚ð•`‰æ
	DrawBox((int)(pos.x), (int)(pos.y),
		(int)(pos.x + CAR_W), (int)(pos.y + CAR_H),
		GetCharaColor(), true);
}

void Car::RepeatMoveLeftRight()
{
	float dt = GetDeltaTime();
	Vector2D pos = GetPos();

	const float left = 0.0f;
	const float right = WIN_WIDTH - CAR_W;

	SetPos(Vector2D(pos.x + GetVel().x * dt, pos.y));
	if (pos.x > right) {
		SetPos(Vector2D(right, pos.y));
		vel_.x = -vel_.x;
	}
	else if (pos.x < left) {
		SetPos(Vector2D(left, pos.y));
		vel_.x = -vel_.x;
	}
}
