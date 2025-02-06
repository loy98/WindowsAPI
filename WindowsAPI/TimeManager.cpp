#include "pch.h"
#include "TimeManager.h"

void TimeManager::Init()
{
	//::GetTickCount64();
	//::GetTickCount64();

	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount));
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_frequency)); //CPU 클럭
}

void TimeManager::Update()
{
	uint64 currentCount;
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount)); //CPU 클럭

	_deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency); //경과된 초
	_prevCount = currentCount; //현재 프레임을 이전프레임에 넣어서 다음 상태를 구한다

	_frameCount++;
	_frameTime += _deltaTime;

	if (_frameTime >= 1.f)
	{
		_fps = static_cast<uint32>(_frameCount / _frameTime);

		_frameTime = 0.f;
		_frameCount = 0;
	}
}
