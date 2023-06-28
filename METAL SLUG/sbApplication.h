#pragma once
#include "Commoninclude.h"


namespace sb
{
	using namespace math;
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();
		void Update();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		Vector2 mPlayerControl;
	};
}

