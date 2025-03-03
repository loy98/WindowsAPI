#include "pch.h"
#include "Missile.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "ObjectManager.h"

Missile::Missile() : Object(ObjectType::Projectile)
{
}

Missile::~Missile()
{
}

void Missile::Init()
{
	_stat.hp = 1;
	_stat.maxHp = 1;

	_stat.speed = 600;
}

void Missile::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	//y축방향이 아닌 포신 방향으로 발사
	_pos.y -= deltaTime * _stat.speed * sin(_angle);
	_pos.x += deltaTime * _stat.speed * cos(_angle);

	// 충돌 처리
	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
	{
		if (object == this)
			continue;

		if (object->GetObjectType() != ObjectType::Monster)
			continue;

		Pos p1 = GetPos();
		Pos p2 = object->GetPos();

		const float dx = p1.x - p2.x;
		const float dy = p1.y - p2.y;

		float dist = sqrt(dx * dx + dy * dy);

		if (dist < 25)
		{
			GET_SINGLE(ObjectManager)->Remove(object);
			GET_SINGLE(ObjectManager)->Remove(this);

			return;
		}
	}

	//TODO
	if (_pos.y < -100)
	{
		GET_SINGLE(ObjectManager)->Remove(this); //본인을 해제했으므로 이후 바로 return해야함
		return;// Object에 속한 데이터들을 다루면 안됨!
	}
}

void Missile::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _pos, 25);	
}
