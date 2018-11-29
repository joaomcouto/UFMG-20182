#include "doctest.h"
#include "battle.h"
#include "enemy.h"
#include "wizard.h"

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

	Battle *battle = new Battle(Harry, Malfoy);

	CHECK_EQ(battle->getCurrentEnemyStats().hp, 100);
	CHECK_EQ(battle->getCurrentEnemyStats().mp, 20);
	CHECK_EQ(battle->getCurrentEnemyStats().level, 1);
	CHECK_EQ(battle->getCurrentEnemyStats().dexterity, 1);
	CHECK_EQ(battle->getCurrentEnemyStats().constitution, 1);
	CHECK_EQ(battle->getCurrentEnemyStats().strenght, 1);

	CHECK_EQ(battle->getCurrentPlayerStats().hp, 0);
	CHECK_EQ(battle->getCurrentPlayerStats().mp, 100);
	CHECK_EQ(battle->getCurrentPlayerStats().level, 1);
	CHECK_EQ(battle->getCurrentPlayerStats().dexterity, 1);
	CHECK_EQ(battle->getCurrentPlayerStats().constitution, 1);
	CHECK_EQ(battle->getCurrentPlayerStats().strenght, 1);

	CHECK_NOTHROW(Battle(Harry, Malfoy));
	delete Harry;
	delete Malfoy;
}
