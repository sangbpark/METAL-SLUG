#include "sbBGDesert.h"
#include "sbTransform.h"

namespace sb
{
	BGDesert::BGDesert()
	{
		Transform* tr = GetComponent<Transform>();
		math::Vector2 pos = tr->GetPosition();
		pos.x = -5.0f;
		pos.y = 300.0f;
		tr->SetPosition(pos);
	}
	BGDesert::~BGDesert()
	{
	
	}
	void BGDesert::Initialize()
	{
		
	}
	void BGDesert::Update()
	{
		GameObject::Update();
	}
	void BGDesert::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}