#include "sbBGMDesert.h"
#include "sbTransform.h"

namespace sb
{
	BGMDesert::BGMDesert()
	{

	}
	BGMDesert::~BGMDesert()
	{

	}
	void BGMDesert::Initialize()
	{
	}
	void BGMDesert::Update()
	{
		GameObject::Update();
		Transform* tr = GetComponent<Transform>();
		math::Vector2 pos = tr->GetPosition();
		pos.x = -20.0f;
		pos.y = 300.0f;
		tr->SetPosition(pos);
	
	}
	void BGMDesert::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}