//Vamo pra batalha, guerreirinho!
#include "doctest.h"
#include "battle.h"
#include "enemy.h"

/* ---------------------------------Não Consegui----------------------------
TEST_CASE("Testing MyPause"){
	CHECK_NOTHROW(myBattlePause())

}*/ 


TEST_CASE("Testing Introduction"){
	std::vector<Spell *> _spells;	
	specialAttack _attack;
  _attack._name = "Incendio";
  _attack._damageStats.hp = -10;

  Enemy *Malfoy = new Enemy("Malfoy","Human", _attack, 1, 100, 20, 1, 1 ,1, _spells, "Sangue impuro!!");
	
//	CHECK_NOTHROW(introduction());
}

TEST_CASE("Testing Inicilization Battle"){

}


TEST_CASE("Testing Constructor"){
	std::vector<Spell *> _spells;
  std::vector<Potions *> _potions;
  std::vector<Artifacts *> _artifacts;

	Wizard *Harry = new Wizard("Harry Potter", 1, 0, 100, 1, 1, 1, "Gryffindor", "Holly wood and Phoenix feathers", "Deer", _spells, _potions, _artifacts);

	specialAttack _attack;
  _attack._name = "Incendio";
  _attack._damageStats.hp = -10;
	
	Enemy *Malfoy = new Enemy("Malfoy","Human", _attack, 1, 100, 20, 1, 1 ,1, _spells, "Sangue impuro!!");

	CHECK_NOTHROW(Battle(Harry, Malfoy));

}
