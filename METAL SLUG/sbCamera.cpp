#include "sbCamera.h"
#include "sbApplication.h"
#include "sbInput.h"
#include "sbTransform.h"
#include "sbTime.h"

extern sb::Application application;

namespace sb
{
	Vector2 Camera::mResolution = Vector2::Zero;
	Vector2 Camera::mLookPosition = Vector2::Zero;
	Vector2 Camera::mDistance = Vector2::Zero;
	GameObject* Camera::mTarget = nullptr;

	void Camera::Initialize()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
		mLookPosition = mResolution / 2.0f;
	}
	void Camera::Update()
	{
		if (Input::GetKey(eKeyCode::W))
		{
			mLookPosition.y -= 1000.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::A))
		{
			mLookPosition.x -= 1000.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			mLookPosition.y += 1000.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::D))
		{
			mLookPosition.x += 1000.0f * Time::DeltaTime();
		}

		if (mTarget)
		{
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookPosition = tr->GetPosition();
		}

		mDistance = mLookPosition - (mResolution / 2.0f);
	}
}
