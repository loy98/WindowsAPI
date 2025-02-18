#include "pch.h"
#include "InputManager.h"
#include "Game.h"

void InputManager::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_states.resize(KEY_TYPE_COUNT, KeyState::None);
}

void InputManager::Update()
{
	//::GetAsyncKeyState();
	BYTE asciiKeys[KEY_TYPE_COUNT] = {};
	if (::GetKeyboardState(asciiKeys) == false)
	{
		return;
	}
		

	for (uint32 key = 0; key < KEY_TYPE_COUNT; key++)
	{
		//키가 눌려 있으면 true
		if (asciiKeys[key] & 0x80)
		{
			KeyState& state = _states[key];

			//이전 프레임에 키를 누른 상태라면 PRESS
			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Press;
			else
				state = KeyState::Down;
		}
		//키를 뗐다면
		else
		{
			KeyState& state = _states[key];

			//이전 프레임에 키를 누른 상태라면 UP
			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Up;
			else
				state = KeyState::None;
		}

		//A 키가 눌렸는지 확인하는 디버깅코드
		//if (asciiKeys[static_cast<uint8>(KeyType::A)] & 0x80)
		//{
		//	MessageBox(NULL, L"A Key Pressed!", L"Debug", MB_OK);
		//}
	}

	//mouse
	::GetCursorPos(&_mousePos);
	::ScreenToClient(_hwnd, &_mousePos);

}
