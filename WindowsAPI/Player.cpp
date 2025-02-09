#include "pch.h"
#include "Player.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Missile.h"
#include "ObjectManager.h"

Player::Player() : Object(ObjectType::Player)
{
}

Player::~Player()
{
}

void Player::Init()
{
	_stat.hp = 100;
	_stat.maxHp = 100;
	_stat.speed = 500;

	_pos.x = 400;
	_pos.y = 500;
}

void Player::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	//WASD�� Player ��ġ����
	if (GET_SINGLE(InputManager)->GetButton(KeyType::A))
	{
		_pos.x -= _stat.speed * deltaTime;
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::D))
	{
		_pos.x += _stat.speed * deltaTime;
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::W))
	{
		_pos.y -= _stat.speed * deltaTime;
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::S))
	{
		_pos.y += _stat.speed * deltaTime;
	}

	//Q,E�� ���� ��������
	if (GET_SINGLE(InputManager)->GetButton(KeyType::Q))
	{
		_barrelAngle += 10 * deltaTime;
	}
	if (GET_SINGLE(InputManager)->GetButton(KeyType::E))
	{
		_barrelAngle -= 10 * deltaTime;
	}

	//SpaceBar�� �̻��� �߻�
	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::SpaceBar))
	{
		//TODO: �̻��� �߻�
		Missile* missile = GET_SINGLE(ObjectManager)->CreateObject<Missile>();
		//�̻��� ������ = Player ������ġ -> ������ �� ��ġ
		missile->SetPos(Player::GetFirePos());
		//�̻��� ���� = ���� ����
		missile->SetAngle(Player::_barrelAngle);
		GET_SINGLE(ObjectManager)->Add(missile);
	}
}

void Player::Render(HDC hdc)
{
	//Player ������
	Utils::DrawCircle(hdc, _pos, 50);

	//���� ������
	Utils::DrawLine(hdc, _pos, GetFirePos());
}

//���� �׸� �� ������
Pos Player::GetFirePos()
{
	Pos firePos;

	firePos.x = _pos.x + _barrelLength * cos(_barrelAngle);
	firePos.y = _pos.y - _barrelLength * sin(_barrelAngle);

	return firePos;
}
