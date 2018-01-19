#pragma once
#include "Monster.h"

class Scene
{
	Monster *_monsters;
	int _maximumMonsterCount;
public:
	Scene();
	Scene(int);
	Monster* CreateMonster();
	Monster* GetMonsters();
	int GetMaximumMonsterCount();
	~Scene();
};
