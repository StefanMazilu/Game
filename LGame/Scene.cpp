#include "Scene.h"
#include <iostream>

using std::cout;

Scene::Scene()
{

}

Scene::Scene(int maximumMonsterCount)
{
	_maximumMonsterCount = maximumMonsterCount;
	_monsters = new Monster[maximumMonsterCount];

	Monster* monster = CreateMonster();

	if (monster)
	{
		*monster = Monster(10, 10, 10, 10, 10, 10, 5, "Test1");
	}

	monster = CreateMonster();

	if (monster)
	{
		*monster = Monster(10, 10, 10, 10, 40, 10, 10, "Test2");
	}

	monster = CreateMonster();

	if (monster)
	{
		*monster = Monster(1, 1, 1, 1, 1, 1, 1, "Minion");
	}
}

Monster* Scene::CreateMonster()
{
	for (int i = 0; i < _maximumMonsterCount; i++)
	{
		Monster& monster = _monsters[i];
		if (!monster.IsValid())
		{
			cout << "Monster was created. There are " << i + 1 << " monsters in the scene.\n\n";
			return &monster;
		}
	}
	
	return nullptr;
}

Monster* Scene::GetMonsters()
{
	return _monsters;
}

int Scene::GetMaximumMonsterCount()
{
	return _maximumMonsterCount;
}

Scene::~Scene()
{
	delete[] _monsters;
}