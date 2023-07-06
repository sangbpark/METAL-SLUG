#include "sbScene.h"

namespace sb
{
	Scene::Scene()
	{
		mLayers.resize((int)enums::eLayerType::End);
	}
	Scene::~Scene()
	{
	}
	void Scene::Initialize()
	{
		mLayers[(int)enums::eLayerType::Player].AddGameObject();
	}
	void Scene::Update()
	{
		for (Layer& layer : mLayers)
		{
			layer.Update();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (Layer& layer : mLayers)
		{
			layer.Render(hdc);
		}
	}
}