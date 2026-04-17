#include "PlayScene.h"
#include <dinput.h>
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene") {

}

//初期化
void PlayScene::Initialize() {
}

//更新
void PlayScene::Update()
{
	if (Input::IsKeyDown(DIK_0)) {
		SceneManager* sceneManager = (SceneManager*)FindObject("SceneManager");
		sceneManager->ChangeScene(SCENE_ID::SCENE_ID_TEST);
	}
}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}