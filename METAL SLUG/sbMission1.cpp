#include "sbMission1.h"
#include "sbObject.h"
#include "sbSpriteRenderer.h"
#include "sbPlayer.h"
#include "sbResources.h"
#include "sbBackGround.h"
#include "sbTransform.h"
#include "sbGameObject.h"
#include "sbBGDesert.h"
#include "sbBGMDesert.h"


namespace sb
{
	Mission1::Mission1()
	{
	}
	Mission1::~Mission1()
	{
	}
	void Mission1::Initialize()
	{
		Texture* imagesky = Resources::Load<Texture>(L"Mission1BackGroundSky"
			, L"..\\Resource\\Map\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - Mission 1 - sky .bmp");
		BackGround* M1BackGroundSky = object::Instantiate<BackGround>(enums::eLayerType::Backgroud);
		SpriteRenderer* skysr = M1BackGroundSky->AddComponent<SpriteRenderer>();
		skysr->SetImage(imagesky);
		skysr->SetScale(Vector2(2.0f, 3.0f));

		Texture* imageMDesert = Resources::Load<Texture>(L"Mission1BackGroundMDesert"
			, L"..\\Resource\\Map\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - Mission 1 - MoveDesert.png");
		BGMDesert* M1BackGroundMDesert = object::Instantiate<BGMDesert>(enums::eLayerType::Backgroud);
		SpriteRenderer* BGDMsr = M1BackGroundMDesert->AddComponent<SpriteRenderer>();
		BGDMsr->SetImage(imageMDesert);
		BGDMsr->SetScale(Vector2(9.0f, 9.0f));

		Texture* imageDesert = Resources::Load<Texture>(L"Mission1BackGroundDesert"
			, L"..\\Resource\\Map\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - Mission 1-backdesert.png");
		BGDesert* M1BackGroundDesert = object::Instantiate<BGDesert>(enums::eLayerType::Backgroud);
		SpriteRenderer* BGDsr = M1BackGroundDesert->AddComponent<SpriteRenderer>();
		BGDsr->SetImage(imageDesert);
		BGDsr->SetScale(Vector2(5.0f, 6.0f));
	
	
		Texture* imageBG = Resources::Load<Texture>(L"Mission1BackGround"
			, L"..\\Resource\\Map\\Metal Slug 2 Metal Slug X - Mission 1.png");
		BackGround* M1BackGround = object::Instantiate<BackGround>(enums::eLayerType::Backgroud);
		SpriteRenderer* BGsr = M1BackGround->AddComponent<SpriteRenderer>();
		BGsr->SetImage(imageBG);
		BGsr->SetScale(Vector2(3.0f, 3.82f));


	}
	void Mission1::Update()
	{
		Scene::Update();
	}


	void Mission1::Render(HDC hdc)
	{
		Scene::Render(hdc);

	}
}