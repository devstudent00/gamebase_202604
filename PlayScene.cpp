#include "PlayScene.h"
#include <dinput.h>
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/Model.h"

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene"), hModel_(-1) {
	transform_ = {};
	x = 0;
}

//初期化
void PlayScene::Initialize() {
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);
}

//更新
void PlayScene::Update()
{
    const float minX = -20;
	const float maxX = 20;

	if (x <= minX) {
		x += 10;
	}
	else if (x >= maxX) {
		x -= 10;
	}

	transform_.position_ = { x, 0, 0 };
	transform_.scale_ = { 1.0f, 0.5f, 1.0f };
	transform_.rotate_.y += 1.0f;

	if (Input::IsKeyDown(DIK_0)) {
		SceneManager* sceneManager = (SceneManager*)FindObject("SceneManager");
		sceneManager->ChangeScene(SCENE_ID::SCENE_ID_TEST);
	}
}

//描画
void PlayScene::Draw() {
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void PlayScene::Release()
{
}