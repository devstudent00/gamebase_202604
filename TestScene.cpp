#include "TestScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene"), hTitlePicture_(-1) {

}

//初期化
void TestScene::Initialize() {
	hTitlePicture_ = Image::Load("test_text2.png");
	assert(hTitlePicture_ >= 0);
}

//更新
void TestScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE)) {
		//SceneManager* sceneManager = (SceneManager*)FindObject("SceneManager");
		SceneManager* sceneManager = (SceneManager*)(this->GetParent());
		sceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//描画
void TestScene::Draw()
{
	transform_.scale_ = { 1.5, 1.5, 1.5 };
	Image::SetTransform(hTitlePicture_, transform_);
	Image::Draw(hTitlePicture_);
}

//開放
void TestScene::Release()
{
}
