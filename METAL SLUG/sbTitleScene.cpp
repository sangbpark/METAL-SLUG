#include "sbTitleScene.h"
#include "sbPlayer.h"
#include "sbSpriteRenderer.h"
#include "sbObject.h"
#include "sbTexture.h"
#include "sbResources.h"
#include "sbBackGround.h"
#include "sbInput.h"

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
		Texture* image = Resources::Load<Texture>(L"TitleBackGround"
			, L"..\\Resource\\Title\\Metal Slug 2 Title Screen.png");
		
		BackGround* TitleBackGround = object::Instantiate<BackGround>(enums::eLayerType::Backgroud);
		SpriteRenderer* sr = TitleBackGround->AddComponent<SpriteRenderer>();
		sr->SetImage(image);
		sr->SetScale(Vector2(0.92f, 0.94f));
	
	}
	void TitleScene::Update()
	{
		Scene::Update();
		if (Input::GetKeyDown(eKeyCode::H))
		{
			SceneManager::LoadScene(L"Mission1");
		}
	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}