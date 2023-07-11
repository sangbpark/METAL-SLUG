#pragma once
#include <vector>
#include <list>
#include <map>
#include <set>
#include <functional>
#include <string>
#include "framework.h"
#include "sbMath.h"

#pragma comment(lib, "Msimg32.lib")

namespace sb::enums
{
	enum class eLayerType
	{
		Backgroud,
		Player,
		Monster,
		Effect,
		UI,
		End,
	};
	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		End,
	};
}