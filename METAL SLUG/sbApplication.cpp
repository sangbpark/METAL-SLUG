#include "sbApplication.h"
#include "sbInput.h"
#include "sbTime.h"
#include "sbAuto.h"

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

		Time::Initailize();
		Input::Initailize();
		Auto::Initailize();
	}
	void Application::Run()
	{
		Update();
		Render();
	}
	void Application::Update()
	{
		Time::Update();
		Input::Update();
		Auto::Update();
	
	}
	void Application::Render()
	{
		Time::Render(mHdc);
		Auto::Render(mHdc);
	}
}