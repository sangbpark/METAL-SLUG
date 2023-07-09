#include "sbSTAGE1.h"
#include "sbObject.h"
#include "sbSpriteRenderer.h"
#include "sbPlayer.h"

namespace sb
{
	STAGE1::STAGE1()
	{
	}
	STAGE1::~STAGE1()
	{
	}
	void STAGE1::Initialize()
	{
		Player* player = object::Instantiate<Player>(enums::eLayerType::Player);
		player->AddCompotent<SpriteRenderer>();
	}
	void STAGE1::Update()
	{
		Scene::Update();
	}


	void STAGE1::Render(HDC hdc)
	{
		Rectangle(hdc, 500, 500
			, 700, 700);
		Scene::Render(hdc);

	}
}