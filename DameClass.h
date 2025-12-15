#pragma once
#include "BaseChara.h"
class DameClass :
	public BaseChara
{
public:
	DameClass();
	DameClass(const Vector2D& pos, const Vector2D& vel,
		unsigned int color);
	~DameClass();
private:
	void RepeatMoveLeftRight(); //左右に往復移動する（DameClassクラス専用）
	int w_;
	int h_;
};
