#pragma once

enum class ObjectType
{
	None,
	Player,
	Monster,
	Projectile
};


class Object
{
public:
	Object(ObjectType type);
	virtual ~Object();

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;


public:
	ObjectType GetObjectType() { return _type; }

	void SetPos(Pos pos) { _pos = pos; };
	Pos GetPos() { return _pos; }


protected:
	ObjectType _type = ObjectType::None;
	Pos _pos = {};
	Stat _stat = {};


};

