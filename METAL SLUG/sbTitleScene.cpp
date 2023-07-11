#include "sbTitleScene.h"
#include "sbPlayer.h"
#include "sbSpriteRenderer.h"
#include "sbObject.h"
#include "sbImage.h"
#include "sbResources.h"

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
		Image* image = Resources::Load<Image>(L"TitleCharacter"
			, L"..\\Resource\\Character\\Fighter.bmp");
		
		Player* player = object::Instantiate<Player>(enums::eLayerType::Player);
		SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();
		sr->SetImage(image);

		std::wstring name = player->GetName();
	}
	void TitleScene::Update()
	{
		Scene::Update();
	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}