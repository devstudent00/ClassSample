#include <DxLib.h>
#include "Rocket.h"
#include "globals.h"
#include "Input.h"

int size = 30;

namespace {
	const int gravity = 1;
}

Rocket::Rocket()
 : BaseChara(){
}

Rocket::Rocket(const Vector2D& pos, const Vector2D& vel, unsigned int color)
 : BaseChara(pos, vel, color, SHAPE::TRIANGLE){
}

Rocket::~Rocket()
{
}

void Rocket::Update()
{
	if (Input::IsKeyDown(KEY_INPUT_SPACE)) {
		SetVel(Vector2D(GetVel().x, -10));
		isJumping = true;
	}

	if (isJumping) {
		SetPos(Vector2D(GetPos().x, GetPos().y + GetVel().y));
		SetVel(Vector2D(GetVel().x, GetVel().y - gravity));
	}


	if (GetPos().y < 0+size) {
		pos_.x = WIN_WIDTH / 2;
		pos_.y = GROUND_HEIGTH;
		vel_.y = 0;
		isJumping = false;
	}
}

void Rocket::Draw()
{
	const Vector2D& pos = GetPos();
	DrawTriangle(pos.x, pos.y-size, pos.x-size, pos.y, pos.x+size, pos.y, GetCharaColor(), true);
}
