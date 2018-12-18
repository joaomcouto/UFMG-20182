#include "doctest.h"
#include "wizard.h"

TEST_CASE("Testing Construtor"){
    std::vector<Spell *> _spells;
    std::vector<Potions *> _potions;
    std::vector<Artifacts *> _artifacts;
    CHECK_NOTHROW(Wizard("Harry Potter", 1, 100, 0, 1, 1, 1, "Gryffindor", "Holly wood and Phoenix feathers", "Deer", _spells, _potions, _artifacts));
}


TEST_CASE("Testing SkillPoint - Getters and Setters"){
	std::vector<Spell *> _spells;
    std::vector<Potions *> _potions;
    std::vector<Artifacts *> _artifacts;

    Wizard *Harry = new Wizard("Harry Potter", 1, 0, 100, 1, 1, 1, "Gryffindor", "Holly wood and Phoenix feathers", "Deer", _spells, _potions, _artifacts);	
		
	CHECK_EQ(Harry->getHouse(), "Gryffindor");
	CHECK_EQ(Harry->getWand(), "Holly wood and Phoenix feathers");
	CHECK_EQ(Harry->getPatronum(), "Deer");
	
	int _skillPoints = Harry->getSkillPoints();
	CHECK(_skillPoints == 3);
	
	Harry->incrementSkillPoints(2);
	_skillPoints = Harry->getSkillPoints();
	CHECK(_skillPoints == 5);
		
	Harry->incrementSkill(1);
	_skillPoints = Harry->getSkillPoints();
	CHECK(_skillPoints == 4);

	Potions *test = new Potions(0,"test", 0, 0, 0, 0, 0, 0, 1);
	_potions.push_back(test);
	Artifacts *test1 = new Artifacts(0,"test", 0, 0, 0, 0, 0, 0, 1, true, "none");
	_artifacts.push_back(test1);
	Spell *test2 = new Spell(0, "test", 0, 0, 0, 0, 0, 0);
	_spells.push_back(test2);		

	Harry->setArtifactsVector(_artifacts);
	Harry->setPotionsVector(_potions);
	Harry->setSpellVector(_spells);

	CHECK_EQ(Harry->getPotionsVector()[0]->get_hp_effect(), 0);
	CHECK_EQ(Harry->getPotionsVector()[0]->get_level(), 0);
	CHECK_EQ(Harry->getPotionsVector()[0]->get_name(), "test");
	CHECK_EQ(Harry->getPotionsVector()[0]->get_quant(), 1);
	CHECK_EQ(Harry->getPotionsVector()[0]->getDuration(), 0);
	CHECK_EQ(Harry->getPotionsVector()[0]->getEffectsStats().constitution, 0);
	CHECK_EQ(Harry->getPotionsVector()[0]->getEffectsStats().dexterity, 0);
	CHECK_EQ(Harry->getPotionsVector()[0]->getEffectsStats().mp, 0);

	CHECK_EQ(Harry->getArtifactsVector()[0]->get_hp_effect(), 0);
	CHECK_EQ(Harry->getArtifactsVector()[0]->get_level(), 0);
	CHECK_EQ(Harry->getArtifactsVector()[0]->get_name(), "test");
	CHECK_EQ(Harry->getArtifactsVector()[0]->get_exist(), true);
	CHECK_EQ(Harry->getArtifactsVector()[0]->getDuration(), 0);
	CHECK_EQ(Harry->getArtifactsVector()[0]->getEffectsStats().constitution, 0);
	CHECK_EQ(Harry->getArtifactsVector()[0]->getEffectsStats().dexterity, 0);
	CHECK_EQ(Harry->getArtifactsVector()[0]->getEffectsStats().mp, 0);
	CHECK_EQ(Harry->getArtifactsVector()[0]->getSpecialEffect(), "none");

	CHECK_EQ(Harry->getSpellVector()[0]->get_hp_dmg(), 0);
	CHECK_EQ(Harry->getSpellVector()[0]->get_level(), 0);
	CHECK_EQ(Harry->getSpellVector()[0]->get_name(), "test");
	CHECK_EQ(Harry->getSpellVector()[0]->getDuration(), 0);
	CHECK_EQ(Harry->getSpellVector()[0]->getDamageStats().constitution, 0);
	CHECK_EQ(Harry->getSpellVector()[0]->getDamageStats().dexterity, 0);
	CHECK_EQ(Harry->getSpellVector()[0]->getDamageStats().mp, 0);

	delete Harry;
}

TEST_CASE("Testing Wizard's BaseStats"){
	std::vector<Spell *> _spells;
    std::vector<Potions *> _potions;
    std::vector<Artifacts *> _artifacts;

    Wizard *Harry = new Wizard("Harry Potter", 1, 100, 0, 1, 1, 1, "Gryffindor", "Holly wood and Phoenix feathers", "Deer", _spells, _potions, _artifacts);

	Harry->incrementSkill(1);
	int new_HP = Harry->getHP();
	CHECK(new_HP == 110);
	Harry->incrementSkill(2);
	int new_MP = Harry->getMP();
 	CHECK(new_MP == 10);
	Harry->incrementSkill(3);
	int new_STR = Harry->getStrenght();
    CHECK(new_STR == 2);
	Harry->incrementSkill(4);
	int new_CONS = Harry->getConstitution();
    CHECK(new_CONS == 2);
    Harry->incrementSkill(5);
	int new_DEX = Harry->getDexterity();
    CHECK(new_DEX == 2);

	delete Harry;

}

TEST_CASE("Testing Wizard's Instantiate"){
	std::vector<Spell *> _spells;
    std::vector<Potions *> _potions;
    std::vector<Artifacts *> _artifacts;

	Wizard *Harry = new Wizard("Harry Potter", 1, 100, 0, 1, 1, 1, "Gryffindor", "Holly wood and Phoenix feathers", "Deer", _spells, _potions, _artifacts);

	Potions *test = new Potions(0,"test", 0, 0, 0, 0, 0, 0, 1);
	_potions.push_back(test);
	Artifacts *test1 = new Artifacts(0,"test", 0, 0, 0, 0, 0, 0, 1, true, "none");
	_artifacts.push_back(test1);
	Spell *test2 = new Spell(0, "test", 0, 0, 0, 0, 0, 0);
	_spells.push_back(test2);

	Harry->setPotionsVector(_potions);

	CHECK_EQ(Harry->getPotionsVector()[0]->get_name(), "test");
	CHECK_EQ(Harry->instantiate_artifacts(_artifacts), _artifacts);
	CHECK_EQ(Harry->instantiate_potions(_potions), _potions);

	delete Harry;
}

