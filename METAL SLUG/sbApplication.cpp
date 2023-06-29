#include "sbApplication.h"
#include "sbInput.h"

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

		Input::Initailize();
	}
	void Application::Run()
	{
		Update();
		Render();
	}
	void Application::Update()
	{
		Input::Update();

		if (Input::GetKey(eKeyCode::W))
		{
			mPlayerControl.y -= 0.01f;
		}
		if (Input::GetKey(eKeyCode::A))
		{
			mPlayerControl.x -= 0.01f;
		}
		if (Input::GetKey(eKeyCode::S))
		{
			mPlayerControl.y += 0.01f;
		}
		if (Input::GetKey(eKeyCode::D))
		{
			mPlayerControl.x += 0.01f;
		}
	}
	void Application::Render()
	{
		Ellipse(mHdc, 100 + mPlayerControl.x, 100 + mPlayerControl.y
			, 200 + mPlayerControl.x, 200 + mPlayerControl.y);
	}
}