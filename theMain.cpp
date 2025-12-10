#include "DxLib.h"
#include "globals.h"
#include "input.h"
#include "BaseChara.h"
#include <vector>

#include "Car.h"
#include "Rocket.h"
#include "UFO.h"
#include "Balloon.h"

namespace
{
	const int BGCOLOR[3] = { 255, 250, 205 }; // 背景色{ 255, 250, 205 }; // 背景色
	int crrTime;
	int prevTime;

	//BaseChara* chara_array[5];
	std::vector<BaseChara*> chara_vector;

	int SKY_COLOR[3] = { 178, 237, 232 };
	int GREEN_ZONE = 50;
	int GREEN_COLOR = GetColor(50, 205, 50);
}


float gDeltaTime = 0.0f; // フレーム間の時間差

void DxInit()
{
	ChangeWindowMode(true);
	SetWindowSizeChangeEnableFlag(false, false);
	SetMainWindowText("TITLE");
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);
	SetWindowSizeExtendRate(1.0);
	SetBackgroundColor(BGCOLOR[0],BGCOLOR[1],BGCOLOR[2]);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		DxLib_End();
	}

	SetDrawScreen(DX_SCREEN_BACK);
}

void Initialize()
{
	// 初期化処理
	//chara_vector[0] = new Car(Vector2D(20, GROUND_HEIGTH), Vector2D(200.0f, 3.0f), GetColor(255, 255, 255));
	//chara_vector[1] = new Rocket(Vector2D(WIN_WIDTH / 2, GROUND_HEIGTH), Vector2D(1, 0), GetColor(255, 0, 0));
	//chara_vector[2] = new UFO(Vector2D(40, 50), Vector2D(200, 0), GetColor(0, 255, 0));
	//chara_vector[3] = new Balloon(Vector2D(WIN_WIDTH / 2, GROUND_HEIGTH), Vector2D(1, 0), GetColor(0, 0, 255));

	chara_vector.push_back(new Car(Vector2D(20, GROUND_HEIGTH), Vector2D(200.0f, 3.0f), GetColor(255, 255, 255)));
	chara_vector.push_back(new Rocket(Vector2D(WIN_WIDTH / 2, GROUND_HEIGTH), Vector2D(1, 0), GetColor(255, 0, 0)));
	chara_vector.push_back(new UFO(Vector2D(40, 50), Vector2D(200, 0), GetColor(0, 255, 0)));
	chara_vector.push_back(new Balloon(Vector2D(WIN_WIDTH / 2, GROUND_HEIGTH), Vector2D(1, 0), GetColor(0, 0, 255)));

}
void Update()
{
	// 更新処理
	for (BaseChara* chara : chara_vector) {
		chara->Update();
	}

	if (Input::IsKeyDown(KEY_INPUT_B)) {
		chara_vector.push_back(new Balloon(Vector2D(WIN_WIDTH / 2, GROUND_HEIGTH), Vector2D(1, 0), GetColor(0, 0, 255)));
	}

	if (Input::IsKeyDown(KEY_INPUT_C)) {
		if (!chara_vector.empty()) {
			for (BaseChara* chara : chara_vector) {
				delete chara;
			}
			chara_vector.clear();
		}
	}
}

void Draw()
{
	//Vector2D vec = chara_vector[0]->GetVel();
	//DrawFormatString(20, 20, GetColor(0,0,0), "vec: (%f, %f)", chara_vector[0]->GetVel().x, chara_vector[0]->GetVel().y);
	// 描画処理
	for (BaseChara* chara : chara_vector) {
		chara->Draw();
	}
}

void DrawStage() {
	SetBackgroundColor(SKY_COLOR[0], SKY_COLOR[1], SKY_COLOR[2]);

	DrawBox(0, GROUND_HEIGTH + 1,
		WIN_WIDTH, GROUND_HEIGTH + 200,
		GetColor(105, 76, 18), true);

	DrawBox(0, GROUND_HEIGTH + 1,
		WIN_WIDTH, GROUND_HEIGTH + GREEN_ZONE,
		GREEN_COLOR, true);
}


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	DxInit();
	crrTime = GetNowCount();
	prevTime = GetNowCount();

	Initialize();

	while (true)
	{
		ClearDrawScreen();
		Input::KeyStateUpdate(); // キー入力の状態を更新

		crrTime = GetNowCount(); // 現在の時間を取得
		// 前回の時間との差分を計算
		float deltaTime = (crrTime - prevTime) / 1000.0f; // 秒単位に変換
		gDeltaTime = deltaTime; // グローバル変数に保存

		//ここにやりたい処理を書く
		Update();

		Draw();
		DrawStage();

		ScreenFlip();
		WaitTimer(16);

		prevTime = crrTime; // 現在の時間を前回の時間として保存

		if (ProcessMessage() == -1)
			break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			break;
	}

	DxLib_End();
	return 0;
}