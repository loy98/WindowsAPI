#include "pch.h"
#include "TimeManager.h"

void TimeManager::Init()
{
	//::GetTickCount64();
	//::GetTickCount64();

	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount));
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_frequency)); //CPU Ŭ��
}

void TimeManager::Update()
{
	uint64 currentCount;
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount)); //CPU Ŭ��

	_deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency); //����� ��
	_prevCount = currentCount; //���� �������� ���������ӿ� �־ ���� ���¸� ���Ѵ�

	_frameCount++;
	_frameTime += _deltaTime;

	if (_frameTime >= 1.f)
	{
		_fps = static_cast<uint32>(_frameCount / _frameTime);

		_frameTime = 0.f;
		_frameCount = 0;
	}
}
