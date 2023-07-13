#pragma once
#include "sbComponent.h"

namespace sb
{
	using namespace math;
	class Transform : public Component
	{
	public:
		Transform();
		virtual ~Transform();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		
		void SetPosition(Vector2 Postion) { mPosition = Postion; }
		Vector2 GetPosition() { return mPosition; }


	private:
		Vector2 mPosition;
	};
}

