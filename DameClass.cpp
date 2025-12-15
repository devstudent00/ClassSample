#include "DameClass.h"
#include <DxLib.h>
#include "globals.h"

namespace {
	const int DameClass_W = 50;
	const int DameClass_H = 25;
}

DameClass::DameClass()
	:BaseChara(), w_(DameClass_W), h_(DameClass_H)
{
}

DameClass::DameClass(const Vector2D& pos, const Vector2D& vel, unsigned int color)
	:BaseChara(pos, vel, color, SHAPE::RECTANGLE), w_(DameClass_W), h_(DameClass_H)
{
}

DameClass::~DameClass()
{
}

void DameClass::RepeatMoveLeftRight()
{
	float dt = GetDeltaTime();
	Vector2D pos = GetPos();

	const float left = 0.0f;
	const float right = WIN_WIDTH - DameClass_W;

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
