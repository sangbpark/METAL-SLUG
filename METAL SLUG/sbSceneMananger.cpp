#include "sbSceneMananger.h"
#include "sbSTAGE1.h"
#include "sbTitleScene.h"
#include "sbInput.h"


namespace sb
{
	std::map<std::wstring, Scene* > SceneMananger::mScene = {};
	Scene* SceneMananger::mActiveScene = nullptr;


	void SceneMananger::Initialize()
	{
		CreateScene<TitleScene>(L"TitleScene");
		CreateScene<STAGE1>(L"STAGE1");

		LoadScene(L"TitleScene");
	}

	void SceneMananger::Update()
	{
	
		mActiveScene->Update();
	}

	void SceneMananger::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}

	Scene* SceneMananger::LoadScene(const std::wstring& name)
	{
		std::map<std::wstring, Scene*>::iterator iter
			= mScene.find(name);

		if (iter == mScene.end())
			return nullptr;

		mActiveScene = iter->second;

		return iter->second;
	}
}