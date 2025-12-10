#pragma once
#include "BaseChara.h"
class Car :
    public BaseChara
{
public:
    Car();
	Car(const Vector2D& pos, const Vector2D& vel,
		unsigned int color);
	~Car();
	void Update() override; //オーバーライド
	void Draw() override; //オーバーライド
private:
	void RepeatMoveLeftRight(); //左右に往復移動する（Carクラス専用）
	int w_;
	int h_;
};

