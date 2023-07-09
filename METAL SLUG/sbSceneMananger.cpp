#include "sbSceneMananger.h"
#include "sbSTAGE1.h"
#include "sbTitleScene.h"
#include "sbInput.h"
#include "sbTime.h"

namespace sb
{
	std::map<std::wstring, Scene* > SceneMananger::mScene = {};
	Scene* SceneMananger::mActiveScene = nullptr;
	std::queue<std::wstring > SceneMananger::mQueue = {};
	float timeCheck = 0.0f;

	void SceneMananger::Initialize()
	{
		CreateScene<TitleScene>(L"TitleScene");
		CreateScene<STAGE1>(L"STAGE1");

		LoadScene(L"TitleScene");
	}

	void SceneMananger::Update()
	{
		

		timeCheck += Time::DeltaTime();
	
		if (Input::GetKey(eKeyCode::M))
		{
			if(timeCheck > 0.3f)
			{
				LoadScene(ChangeScene());
				timeCheck = 0.0f;
			}
		}
		
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