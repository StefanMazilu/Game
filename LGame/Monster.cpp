#include <iostream>
#include "Monster.h"
#include <string.h>

using std::cout;

Monster::Monster()
{
	_isValid = false;
}

Monster::Monster(int armor, int armorPen, int damage, int energy, int health, int hitRate, int team, char type[])
{
	SetArmor(armor);
	SetArmorPen(armorPen);
	SetDamage(damage);
	SetEnergy(energy);
	_exp = 0; 
	SetHealth(health);
	SetHitRate(hitRate);
	SetTeam(team);
	SetType(type);
	_isValid = true;
}

char* Monster::GetType()
{
	return _type;
}

bool Monster::IsValid()
{
	return _isValid;
}

void Monster::Attack(Monster *monster)
{
	if (!monster->IsDead() && monster->_team != _team)
	{
		int damageDealt = monster->Defend(_damage, _armorPen);
		cout << _type << " attacked " << monster->_type << " for " << damageDealt << " damage!\n\n";
	}
	else if (!monster->IsDead() && monster->_team == _team)
	{
		cout << "Can't attack your own team!\n\n";
	}
	else
	{
		cout << "Nothing to attack!\n\n";
	}
}

int	Monster::Defend(int damage, int armorPen)
{
	int effectiveDamage = damage - _armor + armorPen;
	if (effectiveDamage > 0)
	{
		_health -= effectiveDamage;
		return effectiveDamage;
	}
	else
	{
		return 0;
	}
}


void Monster::LevelUp(int exp)
{
	_exp += exp;
	_armor += _exp;
	if (_armorPen > 0)
	{
		_armorPen += exp;
	}
	_damage += _exp;
	_health += _exp * 2;
	if (_hitRate > 0)
	{
		_hitRate += 1;
	}
}

void Monster::SetArmor(int armor)
{
	_armor = armor;
}

void Monster::SetArmorPen(int armorPen)
{
	_armorPen = armorPen;
}

void Monster::SetDamage(int damage)
{
	_damage = damage;
}

bool Monster::IsDead()
{
	return _health <= 0;
}

void Monster::SetEnergy(int energy)
{
	_energy = energy;
}

void Monster::SetHealth(int health)
{
	_health = health;
}

void Monster::SetHitRate(int hitRate)
{
	_hitRate = hitRate;
}

void Monster::SetTeam(int team)
{
	_team = team;
}

void Monster::SetType(char type[])
{
	strcpy_s(_type, type);
}
