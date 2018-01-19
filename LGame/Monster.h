#pragma once


class Monster
{
	int	_armor;
	int	_armorPen;
	int	_damage;
	int	_energy;
	int	_exp;
	int	_health;
	int	_hitRate;
	bool _isDead;
	int	_team;
	char _type[16];
	bool _isValid;

public:
	Monster();
	Monster(int, int, int, int, int, int, int, char[]);

	char* GetType();
	int GetDamage()
	{
		return _damage;
	}
	bool IsValid();
	void Attack(Monster*);
	int	Defend(int, int);
	void LevelUp(int);
	void SetArmor(int);
	void SetArmorPen(int);
	void SetDamage(int);
	bool IsDead();
	void SetEnergy(int);
	void SetHealth(int);
	void SetHitRate(int);
	void SetTeam(int);
	void SetType(char[]);

};
