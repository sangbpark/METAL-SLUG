#pragma once
#include "sbScene.h"
namespace sb
{
	class STAGE1 : public Scene
	{
	public:
		STAGE1();
		virtual ~STAGE1();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:
	};
}

