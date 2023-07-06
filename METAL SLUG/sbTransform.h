#pragma once
#include "sbComponent.h"

namespace sb
{
	class Transform : public Component
	{
	public:
		Transform();
		virtual ~Transform();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		
		void SetPosition(math::Vector2 Postion) { mPosition = Postion; }
		math::Vector2 GetPosition() { return mPosition; }

	private:
		math::Vector2 mPosition;
	};
}

