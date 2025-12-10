#include "Balloon.h"
#include <DxLib.h>
#include "Input.h"
#include "globals.h"
#include "cmath"

namespace {
	const int gravity = 1; //重力
	const int amplitude = 5; //振れ幅（※大きくすると幅が大きくなる）
	const int period = 1.2f; //周期（※大きくすると、早くなる）
}

Balloon::Balloon()
	:BaseChara() {
}

Balloon::Balloon(const Vector2D& pos, const Vector2D& vel, unsigned int color)
 : BaseChara(pos, vel, color, SHAPE::CIRLCE), angles(0){
}

Balloon::~Balloon()
{
}

void Balloon::Update()
{
	if (Input::IsKeyDown(KEY_INPUT_SPACE) && !isJumping) {
		isJumping = true;
		pos_.x = GetRand(WIN_WIDTH);
		vel_.y = 5;
	}

	if (isJumping) {
		vel_.x = cos(angles * period) * amplitude;

		pos_.x = pos_.x - vel_.x;
		pos_.y = pos_.y - vel_.y;
		angles += 0.1;
	}


	if (pos_.y > WIN_HEIGHT || pos_.y < 0) {
		pos_.x = WIN_WIDTH / 2;
		pos_.y = GROUND_HEIGTH;
		vel_.x = 0;
		vel_.y = 0;
		angles = 0; //角度を0度に
		isJumping = false;
	}
}

void Balloon::Draw()
{
	if (isJumping) {
		DrawCircle(pos_.x, pos_.y, 20, GetCharaColor(), true);
		DrawBox(pos_.x - 2, pos_.y + 20, pos_.x + 2, pos_.y + 60, GetColor(255, 255, 255), true);
	}
}