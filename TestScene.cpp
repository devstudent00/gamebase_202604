#include "TestScene.h"
#include "Engine/Image.h"

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
}

//描画
void TestScene::Draw()
{
	Image::SetTransform(hTitlePicture_, transform_);
	Image::Draw(hTitlePicture_);
}

//開放
void TestScene::Release()
{
}
