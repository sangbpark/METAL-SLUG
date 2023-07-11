#include "sbSpriteRenderer.h"
#include "sbTransform.h"
#include "sbGameObject.h"

namespace sb
{
	SpriteRenderer::SpriteRenderer()
		:Component(enums::eComponentType::SpriteRenderer)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::Render(HDC hdc)
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		math::Vector2 pos = tr->GetPosition();
		
		
		StretchBlt(hdc, (int)pos.x, (int)pos.y
			, mImage->GetWidth(), mImage->GetHeight()
			, mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), SRCCOPY);
	}
}