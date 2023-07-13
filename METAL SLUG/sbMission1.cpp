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
#include "sbCamera.h"
#include "sbDev.h"
#include "sbFrontBackGround.h"
#include "sbMiddleBoss.h"
#include "sbOldMan.h"

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
		Transform* skytr = M1BackGroundSky->GetComponent<Transform>();
		Vector2 skypos = skytr->GetPosition();
		skypos.x = 4900.0f;
		skypos.y = 250.0f;
		skytr->SetPosition(skypos);
		skysr->SetImage(imagesky);
		skysr->SetScale(Vector2(2.0f, 3.0f));

		Texture* imagebosssky = Resources::Load<Texture>(L"Mission1BackGroundbossSky"
			, L"..\\Resource\\Map\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - Mission 1bosssky.png");
		BackGround* M1BackGroundBossSky = object::Instantiate<BackGround>(enums::eLayerType::Backgroud);
		SpriteRenderer* Bskysr = M1BackGroundBossSky->AddComponent<SpriteRenderer>();
		Transform* Bskytr = M1BackGroundBossSky->GetComponent<Transform>();
		Vector2 Bskypos = Bskytr->GetPosition();
		Bskypos.x = 14800.0f;
		Bskypos.y = 150.0f;
		Bskytr->SetPosition(Bskypos);
		Bskysr->SetImage(imagebosssky);
		Bskysr->SetScale(Vector2(7.0f, 8.0f));

		Texture* imageMDesert = Resources::Load<Texture>(L"Mission1BackGroundMDesert"
			, L"..\\Resource\\Map\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - Mission 1 - MoveDesert.png");
		BGMDesert* M1BackGroundMDesert = object::Instantiate<BGMDesert>(enums::eLayerType::Backgroud);
		SpriteRenderer* BGDMsr = M1BackGroundMDesert->AddComponent<SpriteRenderer>();
		Transform* BGDMtr = M1BackGroundMDesert->GetComponent<Transform>();
		Vector2 BGDMpos = BGDMtr->GetPosition();
		BGDMpos.x = 1050.0f;
		BGDMpos.y = 870.0f;
		BGDMtr->SetPosition(BGDMpos);
		BGDMsr->SetImage(imageMDesert);
		BGDMsr->SetScale(Vector2(9.0f, 9.0f));

		Texture* imageDesert = Resources::Load<Texture>(L"Mission1BackGroundDesert"
			, L"..\\Resource\\Map\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - Mission 1-backdesert.png");
		BGDesert* M1BackGroundDesert = object::Instantiate<BGDesert>(enums::eLayerType::Backgroud);
		SpriteRenderer* BGDsr = M1BackGroundDesert->AddComponent<SpriteRenderer>();
		Transform* BGDtr = M1BackGroundDesert->GetComponent<Transform>();
		Vector2 BGDpos = BGDtr->GetPosition();
		BGDpos.x = 2480.0f;
		BGDpos.y = 450.0f;
		BGDtr->SetPosition(BGDpos);
		BGDsr->SetImage(imageDesert);
		BGDsr->SetScale(Vector2(6.0f, 5.0f));
	
	
		Texture* imageBG = Resources::Load<Texture>(L"Mission1BackGround"
			, L"..\\Resource\\Map\\Metal Slug 2 Metal Slug X - Mission 1.png");
		BackGround* M1BackGround = object::Instantiate<BackGround>(enums::eLayerType::Backgroud);
		SpriteRenderer* BGsr = M1BackGround->AddComponent<SpriteRenderer>();
		Transform* BGtr = M1BackGround->GetComponent<Transform>();
		Vector2 BGpos = BGtr->GetPosition();
		BGpos.x = 8200.0f;
		BGpos.y = 290.0f;
		BGtr->SetPosition(BGpos);
		BGsr->SetImage(imageBG);
		BGsr->SetScale(Vector2(4.2f, 3.5f));

		Texture* imagefruit = Resources::Load<Texture>(L"fruit"
			, L"..\\Resource\\Map\\Metal Slug 2 Metal Slug X - Mission 1 - fruit.png");
		BackGround* fruit = object::Instantiate<BackGround>(enums::eLayerType::Backgroud);
		SpriteRenderer* frsr = fruit->AddComponent<SpriteRenderer>();
		Transform* frtr = fruit->GetComponent<Transform>();
		Vector2 frpos = frtr->GetPosition();
		frpos.x = 2500.0f;
		frpos.y = 470.0f;
		frtr->SetPosition(frpos);
		frsr->SetImage(imagefruit);
		frsr->SetScale(Vector2(4.0f, 3.5f));

		Texture* imagefruitcolumn = Resources::Load<Texture>(L"fruitcolumn"
			, L"..\\Resource\\Map\\Metal Slug 2 Metal Slug X - Mission 1 - fruitcolumn.png");
		FrontBackGround* fruitcolumn = object::Instantiate<FrontBackGround>(enums::eLayerType::FrontBackGround);
		SpriteRenderer* fcsr = fruitcolumn->AddComponent<SpriteRenderer>();
		Transform* fctr = fruitcolumn->GetComponent<Transform>();
		Vector2 fcpos = fctr->GetPosition();
		fcpos.x = 2670.0f;
		fcpos.y = 500.0f;
		fctr->SetPosition(fcpos);
		fcsr->SetImage(imagefruitcolumn);
		fcsr->SetScale(Vector2(4.0f, 3.8f));


		Texture* imagemiddleboss = Resources::Load<Texture>(L"middleboss"
			, L"..\\Resource\\Map\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - Mission 1middleboss.png");
		MiddleBoss* middlboss = object::Instantiate<MiddleBoss>(enums::eLayerType::Monster);
		SpriteRenderer* MBsr = middlboss->AddComponent<SpriteRenderer>();
		Transform* MBtr = middlboss->GetComponent<Transform>();
		Vector2 MBpos = MBtr->GetPosition();
		MBpos.x = 8400.0f;
		MBpos.y = 350.0f;
		MBtr->SetPosition(MBpos);
		MBsr->SetImage(imagemiddleboss);
		MBsr->SetScale(Vector2(4.1f, 3.5f));


		Texture* imageNpcOldMan1 = Resources::Load<Texture>(L"NpcOldMan"
			, L"..\\Resource\\Npc\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - POWs Helpful NPCs oldman.png");
		OldMan* NpcOldMan1 = object::Instantiate<OldMan>(enums::eLayerType::Npc);
		SpriteRenderer* OMsr1 = NpcOldMan1->AddComponent<SpriteRenderer>();
		Transform* OMtr1 = NpcOldMan1->GetComponent<Transform>();
		Vector2 OMpos1 = OMtr1->GetPosition();
		OMpos1.x = 2650.0f;
		OMpos1.y = 330.0f;
		OMtr1->SetPosition(OMpos1);
		OMsr1->SetImage(imageNpcOldMan1);
		OMsr1->SetScale(Vector2(4.1f, 3.5f));

		Texture* imageNpcOldMan2 = Resources::Load<Texture>(L"NpcOldMan"
			, L"..\\Resource\\Npc\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - POWs Helpful NPCs oldman.png");
		OldMan* NpcOldMan2 = object::Instantiate<OldMan>(enums::eLayerType::Npc);
		SpriteRenderer* OMsr2 = NpcOldMan2->AddComponent<SpriteRenderer>();
		Transform* OMtr2 = NpcOldMan2->GetComponent<Transform>();
		Vector2 OMpos2 = OMtr2->GetPosition();
		OMpos2.x = 5810.0f;
		OMpos2.y = 285.0f;
		OMtr2->SetPosition(OMpos2);
		OMsr2->SetImage(imageNpcOldMan2);
		OMsr2->SetScale(Vector2(4.1f, 3.5f));


		Texture* imageNpcOldMan3 = Resources::Load<Texture>(L"NpcOldMan"
			, L"..\\Resource\\Npc\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - POWs Helpful NPCs oldman.png");
		OldMan* NpcOldMan3 = object::Instantiate<OldMan>(enums::eLayerType::Npc);
		SpriteRenderer* OMsr3 = NpcOldMan3->AddComponent<SpriteRenderer>();
		Transform* OMtr3 = NpcOldMan3->GetComponent<Transform>();
		Vector2 OMpos3 = OMtr3->GetPosition();
		OMpos3.x = 6800.0f;
		OMpos3.y = 285.0f;
		OMtr3->SetPosition(OMpos3);
		OMsr3->SetImage(imageNpcOldMan3);
		OMsr3->SetScale(Vector2(4.1f, 3.5f));

		Texture* imageNpcOldMan4 = Resources::Load<Texture>(L"NpcOldMan"
			, L"..\\Resource\\Npc\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - POWs Helpful NPCs oldman.png");
		OldMan* NpcOldMan4 = object::Instantiate<OldMan>(enums::eLayerType::Npc);
		SpriteRenderer* OMsr4 = NpcOldMan4->AddComponent<SpriteRenderer>();
		Transform* OMtr4 = NpcOldMan4->GetComponent<Transform>();
		Vector2 OMpos4 = OMtr4->GetPosition();
		OMpos4.x = 8500.0f;
		OMpos4.y = 590.0f;
		OMtr4->SetPosition(OMpos4);
		OMsr4->SetImage(imageNpcOldMan4);
		OMsr4->SetScale(Vector2(4.1f, 3.5f));

		Texture* imageNpcOldMan5 = Resources::Load<Texture>(L"NpcOldMan"
			, L"..\\Resource\\Npc\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - POWs Helpful NPCs oldman.png");
		OldMan* NpcOldMan5 = object::Instantiate<OldMan>(enums::eLayerType::Npc);
		SpriteRenderer* OMsr5 = NpcOldMan5->AddComponent<SpriteRenderer>();
		Transform* OMtr5 = NpcOldMan5->GetComponent<Transform>();
		Vector2 OMpos5 = OMtr5->GetPosition();
		OMpos5.x = 12000.0f;
		OMpos5.y = 590.0f;
		OMtr5->SetPosition(OMpos5);
		OMsr5->SetImage(imageNpcOldMan5);
		OMsr5->SetScale(Vector2(4.1f, 3.5f));
		

		Texture* imagePlayerTop = Resources::Load<Texture>(L"PlayerTop"
			, L"..\\Resource\\Character\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - Marco RossiTop.png");
		Texture* imagePlayerBottom = Resources::Load<Texture>(L"PlayerBottom"
			, L"..\\Resource\\Character\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - Marco Rossibottom.png");
		Player* playerbottom = object::Instantiate<Player>(enums::eLayerType::Player);
		SpriteRenderer* Psr2 = playerbottom->AddComponent<SpriteRenderer>();
		Transform* ptr2 = playerbottom->GetComponent<Transform>();
		Vector2 ppos2 = ptr2->GetPosition();
		ppos2.x = 100.0f;
		ppos2.y = 590.0f;
		ptr2->SetPosition(ppos2);
		Psr2->SetImage(imagePlayerBottom);
		Psr2->SetScale(Vector2(4.1f, 3.5f));
		Player* playerTop = object::Instantiate<Player>(enums::eLayerType::Player);
		SpriteRenderer* Psr = playerTop->AddComponent<SpriteRenderer>();
		Transform* ptr = playerTop->GetComponent<Transform>();
		Vector2 ppos = ptr->GetPosition();
		ppos.x = 100.0f;
		ppos.y = 560.0f;
		ptr->SetPosition(ppos);
		Psr->SetImage(imagePlayerTop);
		Psr->SetScale(Vector2(4.1f, 3.5f));
	
		
		Camera::SetTarget(playerTop);

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