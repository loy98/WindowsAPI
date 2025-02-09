#pragma once
#include "Object.h"
class Missile : public Object
{
public:
	Missile();
	virtual ~Missile() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	//Player에서 발사하는 미사일 설정할 때 사용
	//우선은 미사일에서만 사용하므로 Manager가 아닌 Missile에서 관리
	void SetAngle(float angle) { _angle = angle; } 
private:
	float _angle = 0.f;
};

