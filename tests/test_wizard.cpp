#include "doctest.h"
#include "wizard.h"

TEST_CASE("Testing Construtor"){
    std::vector<Spell *> _spells;
    std::vector<Potions *> _potions;
    std::vector<Artifacts *> _artifacts;
    CHECK_NOTHROW(Wizard *Harry = new Wizard("Harry Potter", 1, 100, 100, 1, 1, 1, "Gryffindor", "Holly wood and Phoenix feathers", "Deer", _spells, _potions, _artifacts));
}


TEST_CASE("Testing SkillPoint - Getters and Setters"){
		std::vector<Spell *> _spells;
    std::vector<Potions *> _potions;
    std::vector<Artifacts *> _artifacts;		
    Wizard *Harry = new Wizard("Harry Potter", 1, 100, 100, 1, 1, 1, "Gryffindor", "Holly wood and Phoenix feathers", "Deer", _spells, _potions, _artifacts);	
		
		int _skillPoints = Harry->getSkillPoints();
			CHECK(_skillPoints == 3);
	
		Harry->incrementSkillPoints(2);
		_skillPoints = Harry->getSkillPoints();
			CHECK(_skillPoints == 5);

		Harry->incrementSkill(1);
		_skillPoints = Harry->getSkillPoints();
			CHECK(_skillPoints == 4);
}
