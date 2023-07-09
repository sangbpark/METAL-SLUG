#include "sbTitleScene.h"
#include "sbPlayer.h"
#include "sbObject.h"
#include "sbSpriteRenderer.h"

namespace sb
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		Player* player = object::Instantiate<Player>(enums::eLayerType::Player);
		player->AddCompotent<SpriteRenderer>();
	}
	void TitleScene::Update()
	{
		Scene::Update();
	}
	void TitleScene::Render(HDC hdc)
	{
		Ellipse(hdc, 500 , 500 
			, 700  , 700 );
		Scene::Render(hdc);
	}
}