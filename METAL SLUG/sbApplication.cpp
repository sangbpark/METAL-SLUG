#include "sbApplication.h"
#include "sbInput.h"
#include "sbTime.h"
#include "sbAuto.h"

namespace sb
{

	Application::Application()
		: mHwnd(NULL)
		, mHdc(NULL)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(NULL)
		, mBackBuffer(NULL)
	{
	}
	Application::~Application()
	{
	}
	void Application::Initialize(HWND hWnd)
	{
		mHwnd = hWnd;
		mHdc = GetDC(mHwnd);

		mWidth = 1600;
		mHeight = 900;

		RECT rect = { 0,0,mWidth,mHeight };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		SetWindowPos(mHwnd
			, nullptr ,0 ,0
			, rect.right - rect.left
			, rect.bottom - rect.top
			, 0);
		ShowWindow(mHwnd, true);

		mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);

		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP defaultBitmap
			= (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(defaultBitmap);

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
		Rectangle(mBackHdc, -1, -1, mWidth + 1, mHeight + 1);

		Auto::Render(mBackHdc);

		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);

	}
}