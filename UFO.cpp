#include "UFO.h"
#include <DxLib.h>
#include "globals.h"
#include <cmath>

UFO::UFO()
 : BaseChara(){
}

UFO::UFO(const Vector2D& pos, const Vector2D& vel, unsigned int color)
 : BaseChara(pos, vel, color, SHAPE::CIRLCE){
}

UFO::~UFO()
{
}

void UFO::Update()
{
	RepeatMoveLeftRight();
}

void UFO::Draw()
{
	const Vector2D& pos = GetPos();
	DrawCircle(pos.x, pos.y, 20, GetCharaColor(), true);
}

void UFO::RepeatMoveLeftRight()
{
	float dt = GetDeltaTime();

	const float left = 0.0f;
	const float right = WIN_WIDTH - 20;

	static double radius = 0; //Šp“x
	static int direction = 1; //•ûŒü

	vel_.x = 2 * direction;
	vel_.y = sin(radius * 1.2f) * 10;

	pos_.x = pos_.x + vel_.x; 
	pos_.y = pos_.y + vel_.y;
	
	radius += 0.1; //Šp“x‚ð•Ï‚¦‚Ä‚¢‚­
	if (pos_.x > right) {
		pos_.x = right;
		direction *= -1;
	}
	else if (pos_.x < left) {
		pos_.x = left;
		direction *= -1;
	}
}
