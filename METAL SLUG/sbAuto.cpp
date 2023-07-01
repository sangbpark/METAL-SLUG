#include "sbAuto.h"


namespace sb
{
	std::vector<Auto::Direct> Auto::mDirect = {};
	std::vector<math::Vector2> Auto::mAuto = {};
	static float timecheck = 0.0f;
	static int cyclecount = 0;

	void Auto::Initailize()
	{
		Direct Direct = {};
		Direct.Directx = false;
		Direct.Directy = false;

		mDirect.push_back(Direct);

		math::Vector2 Auto = {};
		Auto.x = 0.0f;
		Auto.y = 0.0f;
		mAuto.push_back(Auto);
	}
	void Auto::Update()
	{
		
		
		timecheck += Time::DeltaTime();

		if (timecheck > 3.0f)
		{
			srand(time(NULL));
			int RandomDirectx = 0;
			int RandomDirecty = 0;

			RandomDirectx = rand();
			RandomDirecty = rand();
			
			Direct Direct = {};

			if (RandomDirectx % 2 == 0)
				Direct.Directx = false;
			else
				Direct.Directx = true;

			if (RandomDirecty % 2 == 0)
				Direct.Directy = false;
			else
				Direct.Directy = true;

			mDirect.push_back(Direct);

			math::Vector2 Auto = {};
			Auto.x = 0.0f;
			Auto.y = 0.0f;
			mAuto.push_back(Auto);

			cyclecount += 1;
			timecheck = 0.0f;
		}
		for (size_t i = 0; i <= cyclecount; i++) 
		{
			for (size_t e = 0; e <=	 cyclecount - i; e++) // °¡¼Ó
			{
				if (200 + mAuto[i].x > (int)DisplayResolution::endDisplayx)
					mDirect[i].Directx = true;
				if (100 + mAuto[i].x < (int)DisplayResolution::startDisplayx)
					mDirect[i].Directx = false;
				if (258 + mAuto[i].y > (int)DisplayResolution::endDisplayy)
					mDirect[i].Directy = true;
				if (100 + mAuto[i].y < (int)DisplayResolution::startDisplayy)
					mDirect[i].Directy = false;

				if (mDirect[i].Directx == true)
					mAuto[i].x -= 300.0f * Time::DeltaTime();
				if (mDirect[i].Directy == true)
					mAuto[i].y -= 200.0f * Time::DeltaTime();
				if (mDirect[i].Directx == false)
					mAuto[i].x += 300.0f * Time::DeltaTime();
				if (mDirect[i].Directy == false)
					mAuto[i].y += 300.0f * Time::DeltaTime();
			}
		}

	}
	void Auto::Render(HDC hdc)
	{
		for (size_t i = 0; i <= cyclecount; i++)
		{
			Ellipse(hdc, 100 + mAuto[i].x, 100 + mAuto[i].y
				, 200 + mAuto[i].x, 200 + mAuto[i].y);

		}
	}
}