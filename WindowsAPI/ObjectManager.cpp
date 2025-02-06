#include "pch.h"
#include "Object.h"
#include "ObjectManager.h"

ObjectManager::~ObjectManager()
{
	Clear();
}

void ObjectManager::Add(Object* object)
{
	if (object == nullptr)
		return;

	auto findIt = find(_objects.begin(), _objects.end(), object);
	if (findIt != _objects.end())
		return;

	_objects.push_back(object);
}

void ObjectManager::Remove(Object* object)
{
	if (object == nullptr)
		return;

	auto findIt = remove(_objects.begin(), _objects.end(), object);
	_objects.erase(findIt, _objects.end());

	delete object;
}

void ObjectManager::Clear()
{
	for_each(_objects.begin(), _objects.end(), [=](Object* obj) { delete obj; });

	_objects.clear();
}
