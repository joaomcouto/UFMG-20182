#include "doctest.h"
#include "wizard.h"
#include "spells.h"
#include "artifacts.h"
#include "potions.h"
#include <string.h>
#include <cstring>

TEST_CASE("Testing Getters and Setters"){
	std::vector<Spell *> _spells;
	std::vector<Potions *> _potions;
	std::vector<Artifacts *> _artifacts;

	Character *Sirius = new Wizard("Sirius Black", 1, 100, 0, 1, 1, 1, "Grifinoria", " ", " ",  _spells, _potions, _artifacts);	

	std::string name = Sirius->getName();
		CHECK_EQ(name, "Sirius Black");
	int level = Sirius->getLevel();
		CHECK(level == 1);
	int hp = Sirius->getHP();
		CHECK(hp == 100);
	int mp = Sirius->getMP();
		CHECK(mp == 0);
	int str = Sirius->getStrenght();
		CHECK(str == 1);
	int cons = Sirius->getConstitution();
		CHECK(cons == 1);
	int dex = Sirius->getDexterity();
		CHECK(dex == 1);

	Stats new_stats;
	new_stats.level = 7;
	new_stats.hp = 170;
	new_stats.mp = 70;
	new_stats.strenght = 7;
	new_stats.constitution = 7;
	new_stats.dexterity = 7;

	Sirius->setStats(new_stats);
	Stats _stats = Sirius->getBaseStats();
	
	CHECK(new_stats.level == _stats.level);
	CHECK(new_stats.hp == _stats.hp);
	CHECK(new_stats.mp == _stats.mp);
	CHECK(new_stats.strenght == _stats.strenght);
	CHECK(new_stats.constitution == _stats.constitution);
	CHECK(new_stats.dexterity == _stats.dexterity);


}
