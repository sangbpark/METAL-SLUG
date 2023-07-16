#include "sbMission1.h"
#include "sbObject.h"
#include "sbSpriteRenderer.h"
#include "sbPlayerTop.h"
#include "sbPlayerBottom.h"
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
#include "sbCameraPlayer.h"
#include "sbAnimator.h"

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
			, L"..\\Resource\\Map\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - Mission sky.bmp");
		BackGround* M1BackGroundSky = object::Instantiate<BackGround>(enums::eLayerType::Backgroud);
		SpriteRenderer* skysr = M1BackGroundSky->AddComponent<SpriteRenderer>();
		Transform* skytr = M1BackGroundSky->GetComponent<Transform>();
		skytr->SetPosition(Vector2(4000.0f, 250.0f));
		skysr->SetImage(imagesky);
		skysr->SetScale(Vector2(4.0f, 6.0f));
	

		Texture* imagebosssky = Resources::Load<Texture>(L"Mission1BackGroundbossSky"
			, L"..\\Resource\\Map\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - Mission 1bosssky.png");
		BackGround* M1BackGroundBossSky = object::Instantiate<BackGround>(enums::eLayerType::Backgroud);
		SpriteRenderer* Bskysr = M1BackGroundBossSky->AddComponent<SpriteRenderer>();
		Transform* Bskytr = M1BackGroundBossSky->GetComponent<Transform>();
		Bskytr->SetPosition(Vector2(14800.0f, 150.0f));
		Bskysr->SetImage(imagebosssky);
		Bskysr->SetScale(Vector2(7.0f, 8.0f));

		Texture* imageMDesert = Resources::Load<Texture>(L"Mission1BackGroundMDesert"
			, L"..\\Resource\\Map\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - Mission 1-mbackdesert.bmp");
		BGMDesert* M1BackGroundMDesert = object::Instantiate<BGMDesert>(enums::eLayerType::Backgroud);
		Transform* BGDMtr = M1BackGroundMDesert->GetComponent<Transform>();
		BGDMtr->SetPosition(Vector2(500.0f, 200.0f));
		Animator* BGDat = M1BackGroundMDesert->AddComponent<Animator>();
		BGDat->CreateAnimation(L"Mission1BackGroundMDesertAY", imageMDesert
			, Vector2(0.0f, 0.0f), Vector2(249.0f, 35.0f), 4);
		BGDat->PlayAnimation(L"Mission1BackGroundMDesertAY",true);
		

		Texture* imageDesert = Resources::Load<Texture>(L"Mission1BackGroundDesert"
			, L"..\\Resource\\Map\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - Mission 1-backdesert.bmp");
		BGDesert* M1BackGroundDesert = object::Instantiate<BGDesert>(enums::eLayerType::Backgroud);
		SpriteRenderer* BGDsr = M1BackGroundDesert->AddComponent<SpriteRenderer>();
		Transform* BGDtr = M1BackGroundDesert->GetComponent<Transform>();
		BGDtr->SetPosition(Vector2(2900.0f, 450.0f));
		BGDsr->SetImage(imageDesert);
		BGDsr->SetScale(Vector2(6.0f, 5.0f));
	
	
		Texture* imageBG = Resources::Load<Texture>(L"Mission1BackGround"
			, L"..\\Resource\\Map\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - Mission 1d.bmp");
		BackGround* M1BackGround = object::Instantiate<BackGround>(enums::eLayerType::Backgroud);
		SpriteRenderer* BGsr = M1BackGround->AddComponent<SpriteRenderer>();
		Transform* BGtr = M1BackGround->GetComponent<Transform>();
		BGtr->SetPosition(Vector2(7900.0f, 290.0f));
		BGsr->SetImage(imageBG);
		BGsr->SetScale(Vector2(4.2f, 3.5f));
	
		Texture* imageBGboss = Resources::Load<Texture>(L"Mission1bossbackground"
			, L"..\\Resource\\Map\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - Mission 1bosssky.bmp");
		BackGround* M1BackGroundboss = object::Instantiate<BackGround>(enums::eLayerType::Backgroud);
		Transform* BGBtr = M1BackGroundboss->GetComponent<Transform>();
		BGBtr->SetPosition(Vector2(500.0f, 200.0f));
		Animator* BGBat = M1BackGroundboss->AddComponent<Animator>();
		BGBat->CreateAnimation(L"mission1bossbackgroundAX", imageBGboss
			, Vector2(0.0f, 0.0f), Vector2(307.0f, 208.0f), 4);
		BGBat->PlayAnimation(L"mission1bossbackgroundAX", true);
		
		Texture* imagefruit = Resources::Load<Texture>(L"fruit"
			, L"..\\Resource\\Map\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - Missionfruit 1.bmp");
		BackGround* fruit = object::Instantiate<BackGround>(enums::eLayerType::Backgroud);
		SpriteRenderer* frsr = fruit->AddComponent<SpriteRenderer>();
		Transform* frtr = fruit->GetComponent<Transform>();
		frtr->SetPosition(Vector2(2500.0f, 550.0f));
		frsr->SetImage(imagefruit);
		frsr->SetScale(Vector2(4.0f, 3.0f));

		Texture* imagefruitcolumn = Resources::Load<Texture>(L"fruitcolumn"
			, L"..\\Resource\\Map\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - Missionfruitcoulmn 1.bmp");
		FrontBackGround* fruitcolumn = object::Instantiate<FrontBackGround>(enums::eLayerType::FrontBackGround);
		SpriteRenderer* fcsr = fruitcolumn->AddComponent<SpriteRenderer>();
		Transform* fctr = fruitcolumn->GetComponent<Transform>();
		fctr->SetPosition(Vector2(2660.0f, 550.0f));
		fcsr->SetImage(imagefruitcolumn);
		fcsr->SetScale(Vector2(4.0f, 3.0f));


		Texture* imagemiddleboss = Resources::Load<Texture>(L"middleboss"
			, L"..\\Resource\\Map\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - Mission 1middleboss.png");
		MiddleBoss* middlboss = object::Instantiate<MiddleBoss>(enums::eLayerType::Monster);
		SpriteRenderer* MBsr = middlboss->AddComponent<SpriteRenderer>();
		Transform* MBtr = middlboss->GetComponent<Transform>();
		MBtr->SetPosition(Vector2(8400.0f, 350.0f));
		MBsr->SetImage(imagemiddleboss);
		MBsr->SetScale(Vector2(4.1f, 3.5f));


		Texture* imageNpcOldMan = Resources::Load<Texture>(L"NpcOldMan"
			, L"..\\Resource\\Npc\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - POWs Helpful NPCs.bmp");
		OldMan* NpcOldMan1 = object::Instantiate<OldMan>(enums::eLayerType::Npc);
		Transform* OMtr1 = NpcOldMan1->GetComponent<Transform>();
		OMtr1->SetPosition(Vector2(650.0f, 330.0f));
		Animator* OMat1 = NpcOldMan1->AddComponent<Animator>();
		OMat1->CreateAnimation(L"NpcOldManIdleAX", imageNpcOldMan, Vector2(0.0f, 11.0f), Vector2(42.0f, 42.0f), 4);
		OMat1->PlayAnimation(L"NpcOldManIdleAX",true);
		OMat1->SetAffectedCamera(false);



		OldMan* NpcOldMan2 = object::Instantiate<OldMan>(enums::eLayerType::Npc);
		SpriteRenderer* OMsr2 = NpcOldMan2->AddComponent<SpriteRenderer>();
		Transform* OMtr2 = NpcOldMan2->GetComponent<Transform>();
		OMtr2->SetPosition(Vector2(5810.0f, 285.0f));
		Animator* OMat2 = NpcOldMan1->AddComponent<Animator>();
		OMat2->CreateAnimation(L"NpcOldManIdleAX", imageNpcOldMan, Vector2(0.0f, 11.0f), Vector2(42.0f, 42.0f), 4);
		OMat2->PlayAnimation(L"NpcOldManIdleAX", true);
		OMat2->SetAffectedCamera(false);


		
		OldMan* NpcOldMan3 = object::Instantiate<OldMan>(enums::eLayerType::Npc);
		SpriteRenderer* OMsr3 = NpcOldMan3->AddComponent<SpriteRenderer>();
		Transform* OMtr3 = NpcOldMan3->GetComponent<Transform>();
		Animator* OMat3 = NpcOldMan1->AddComponent<Animator>();
		OMat3->CreateAnimation(L"NpcOldManIdleAX", imageNpcOldMan, Vector2(0.0f, 11.0f), Vector2(42.0f, 42.0f), 4);
		OMat3->PlayAnimation(L"NpcOldManIdleAX", true);
		OMat3->SetAffectedCamera(false);

		
		OldMan* NpcOldMan4 = object::Instantiate<OldMan>(enums::eLayerType::Npc);
		SpriteRenderer* OMsr4 = NpcOldMan4->AddComponent<SpriteRenderer>();
		Transform* OMtr4 = NpcOldMan4->GetComponent<Transform>();
		Animator* OMat4 = NpcOldMan1->AddComponent<Animator>();
		OMat4->CreateAnimation(L"NpcOldManIdleAX", imageNpcOldMan, Vector2(0.0f, 11.0f), Vector2(42.0f, 42.0f), 4);
		OMat4->PlayAnimation(L"NpcOldManIdleAX", true);
		OMat4->SetAffectedCamera(false);
		
		OldMan* NpcOldMan5 = object::Instantiate<OldMan>(enums::eLayerType::Npc);
		SpriteRenderer* OMsr5 = NpcOldMan5->AddComponent<SpriteRenderer>();
		Transform* OMtr5 = NpcOldMan5->GetComponent<Transform>();
		Animator* OMat5 = NpcOldMan1->AddComponent<Animator>();
		OMat5->CreateAnimation(L"NpcOldManIdleAX", imageNpcOldMan, Vector2(0.0f, 11.0f), Vector2(42.0f, 42.0f), 4);
		OMat5->PlayAnimation(L"NpcOldManIdleAX", true);
		OMat5->SetAffectedCamera(false);
		

		Texture* imagePlayer = Resources::Load<Texture>(L"Player"
			, L"..\\Resource\\Character\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - Marco Rossi.bmp");
	
		PlayerBottom* playerbottom = object::Instantiate<PlayerBottom>(enums::eLayerType::Player);
		Transform* ptr2 = playerbottom->GetComponent<Transform>();
		ptr2->SetPosition(Vector2(600.0f, 590.0f));
		Animator* pb = playerbottom->AddComponent<Animator>();
		pb->CreateAnimation(L"PlayerIdleBAX", imagePlayer, Vector2(147.0f, 258.0f), Vector2(34.0f, 34.0f), 1);
		pb->CreateAnimation(L"PlayerrightBAX", imagePlayer, Vector2(6.0f, 506.0f), Vector2(37.0f, 25.0f), 12,Vector2(-20.0f,5.0f));
		pb->CreateAnimation(L"PlayerdeadBAX", imagePlayer, Vector2(906.0f, 53.0f), Vector2(44.0f, 44.0f), 19, Vector2(0.0f, -5.0f));
		pb->PlayAnimation(L"PlayerIdleBAX", true);

		PlayerTop* playerTop = object::Instantiate<PlayerTop>(enums::eLayerType::Player);
		Transform* ptr = playerTop->GetComponent<Transform>();
		ptr->SetPosition(Vector2(600.0f, 581.0f));
		Animator* pt = playerTop->AddComponent<Animator>();
		pt->CreateAnimation(L"PlayerIdleTAX", imagePlayer, Vector2(7.0f, 258.0f), Vector2(34.0f, 34.0f), 4);
		pt->CreateAnimation(L"PlayerrightTAX", imagePlayer, Vector2(7.0f, 472.0f), Vector2(37.0f, 34.0f), 12,Vector2(-20.0f,-2.0f));
		pt->CreateAnimation(L"PlayerdeadTAX", imagePlayer, Vector2(0.0f, 0.0f), Vector2(0.0f, 0.0f), 12, Vector2(-20.0f, -2.0f));
		pt->PlayAnimation(L"PlayerIdleTAX", true);



		Texture* imageCameraPlayer = Resources::Load<Texture>(L"CameraPlayer"
			, L"..\\Resource\\Character\\Neo Geo NGCD - Metal Slug 2 Metal Slug X - Marco Rossi.bmp");
		CameraPlayer* cameraplayer = object::Instantiate<CameraPlayer>(enums::eLayerType::Player);
		SpriteRenderer* cpsr = cameraplayer->AddComponent<SpriteRenderer>();
		Transform* cptr = cameraplayer->GetComponent<Transform>();
		cptr->SetPosition(Vector2(600.0f, 400.0f));
		cpsr->SetImage(imageCameraPlayer);
		cpsr->SetAlpha(0.0f);
	
		
		Camera::SetTarget(cameraplayer);

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