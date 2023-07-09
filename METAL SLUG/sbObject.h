#pragma once
#include "sbScene.h"
#include "sbGameObject.h"
#include "sbSceneMananger.h"

namespace sb::object
{
	template <typename T>
	static __forceinline T* Instantiate(enums::eLayerType type)
	{
		T* gameObject = new T();
		Scene* scene = SceneMananger::GetActiveScene();
		scene->AddGameObject(type, gameObject);

		return gameObject;
	}
}