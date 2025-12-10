#pragma once
#include "BaseChara.h"
class UFO :
    public BaseChara
{
public:
    UFO();
    UFO(const Vector2D& pos, const Vector2D& vel,
        unsigned int color);
    ~UFO();
    void Update() override; //オーバーライド
    void Draw() override; //オーバーライド
    void RepeatMoveLeftRight();
};

