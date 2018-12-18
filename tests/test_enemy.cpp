#include "doctest.h"
#include "enemy.h"

TEST_CASE("Testing Constructor"){
	std::vector<Spell *> _spells;
	specialAttack _attack;
	_attack._name = "Incendio";
	_attack._damageStats.hp = -10;
	CHECK_NOTHROW(Enemy("Malfoy","Human", _attack, 1, 100, 0, 1, 1 ,1, _spells, "Sangue impuro!!"));
}

TEST_CASE("Testing DecrementSkill"){
	std::vector<Spell *> _spells;
  	specialAttack _attack;
	Enemy *Malfoy = new Enemy("Malfoy","Human", _attack, 1, 100, 20, 1, 1 ,1, _spells, "Sangue impuro!!");
	
	Malfoy->decrementSkill(1);
	int new_hp = Malfoy->getHP();
	CHECK(new_hp == 90);

	Malfoy->decrementSkill(2);
	int new_mp = Malfoy->getMP();
	CHECK(new_mp == 10);
	
	delete Malfoy;
}

TEST_CASE("Testing Getters"){
	std::vector<Spell *> _spells;
  	specialAttack _attack;
  	_attack._name = "Incendio";
  	_attack._damageStats.hp = -10;
	Enemy *Malfoy = new Enemy("Malfoy","Human", _attack, 1, 100, 20, 1, 1 ,1, _spells, "Sangue impuro!!");
	std::string _type = Malfoy->getType();
	CHECK_EQ(_type, "Human");
	
	specialAttack Attack = Malfoy->getSpecialAttack();
	CHECK_EQ(Attack._name, "Incendio");
	CHECK_EQ(Attack._damageStats.hp, -10);
//	CHECK_EQ(Attack._damageStats.mp, 0);
	delete Malfoy;
}
