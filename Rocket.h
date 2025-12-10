#pragma once
#include "BaseChara.h"
class Rocket :
    public BaseChara
{
public:
    Rocket();
    Rocket(const Vector2D& pos, const Vector2D& vel,
        unsigned int color);
    ~Rocket();
    void Update() override; //オーバーライド
    void Draw() override; //オーバーライド
private:
    bool isJumping = false;
};

