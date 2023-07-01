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
	class Auto
	{
	public:
		struct Direct
		{
			bool Directx;
			bool Directy;
		};

		static void Initailize();
		static void Update();
		static void Render(HDC hdc);
	private:
		static std::vector<Direct> mDirect;
		
		static std::vector<math::Vector2> mAuto;
	};
}


