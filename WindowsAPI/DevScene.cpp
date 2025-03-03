#include "pch.h"
#include "DevScene.h"
#include "Utils.h"
#include "InputManager.h"
#include "TimeManager.h"

DevScene::DevScene()
{
}

DevScene::~DevScene()
{
}

void DevScene::Init()
{
}

void DevScene::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();


	if (GET_SINGLE(InputManager)->GetButton(KeyType::A))
	{
		_playerPos.x -= _speed * deltaTime;
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::D))
	{
		_playerPos.x += _speed * deltaTime;
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::W))
	{
		_playerPos.y -= _speed * deltaTime;
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::S))
	{
		_playerPos.y += _speed * deltaTime;
	}

}

void DevScene::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _playerPos, 50);
	{
		wstring str = std::format(L"posX : {0}", _playerPos.x);
		::TextOut(hdc, 300, 10, str.c_str(), static_cast<int32>(str.size()));

	}

}
