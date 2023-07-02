#pragma once
#include "Commoninclude.h"
#include "sbTime.h"
#include <stdlib.h>
#include <time.h>

namespace sb
{

	enum class DisplayResolution
	{
		startDisplayx = 0,
		startDisplayy = 0,
		endDisplayx = 1600,
		endDisplayy = 900,

	};

	enum class SizeError
	{
		left = -100,
		right = 115,
		top,
		bottom = 58 ,
	};

	class Auto
	{
	public:
		struct Direct
		{
			bool Directx;
			bool Directy;
		};

		struct FirstPosition
		{
			float FirstPositionleft;
			float FirstPositionright;
			float FirstPositiontop;
			float FirstPositionbottom;
		};

		static void Initailize();
		static void Update();
		static void Render(HDC hdc);
	private:
		static std::vector<Direct> mDirect;
		static std::vector< FirstPosition> mFirstPosition;
		static std::vector<math::Vector2> mAuto;
	};
}


