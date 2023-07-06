#pragma once
#include "sbEntity.h"
#include "sbLayer.h"

namespace sb

{
	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);

	private:
		std::vector<Layer> mLayers;
	};
}

