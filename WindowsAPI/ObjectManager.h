#pragma once

class Object;

class ObjectManager
{
public:

	DECLARE_SINGLE(ObjectManager)

	~ObjectManager();

	void Add(Object* object);
	void Remove(Object* object);
	void Clear();

	const vector<Object*>& GetObjects() { return _objects; }

	template<typename T>
	T* CreateObject()
	{
		//static_assert(std::is_convertible_v<T*, Object*>);// 템플릿이 특정 타입이어야만 할 때 

		T* object = new T();
		object->Init();

		return object;
	}

private:
	vector<Object*> _objects;

};

