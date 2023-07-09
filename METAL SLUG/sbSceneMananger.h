#pragma once
#include "sbScene.h"
#include <queue>

namespace sb
{
	class SceneMananger
	{
	public:
	
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		template <typename T>
		static T* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			mScene.insert(std::make_pair(name, scene));
			mActiveScene = scene;
			scene->Initialize();
			mQueue.push(name);
			return scene;

		}

		static Scene* LoadScene(const std::wstring& name);
		static Scene* GetActiveScene() { return mActiveScene; }

		static std::wstring ChangeScene()
		{
			std::wstring name = mQueue.front();
			mQueue.pop();
			mQueue.push(name);
		
			return mQueue.front();
		}

	private:
		static std::map<std::wstring, Scene* > mScene;
		static Scene* mActiveScene;
		static std::queue<std::wstring> mQueue;
	};
}

