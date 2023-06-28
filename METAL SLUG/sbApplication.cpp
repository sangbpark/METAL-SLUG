#include "sbApplication.h"

namespace sb
{
	Application::Application()
		: mHwnd(NULL)
		, mHdc(NULL)
	{
	}
	Application::~Application()
	{
	}
	void Application::Initialize(HWND hWnd)
	{
		mHwnd = hWnd;
		mHdc = GetDC(mHwnd);
	}
	void Application::Run()
	{
		Update();
		Render();
	}
	void Application::Update()
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mPlayerControl.x -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mPlayerControl.x += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mPlayerControl.y -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mPlayerControl.y += 0.01f;
		}

	}
	void Application::Render()
	{
		Ellipse(mHdc, 100 + mPlayerControl.x, 100 + mPlayerControl.y
			, 200 + mPlayerControl.x, 200 + mPlayerControl.y);
	}
}