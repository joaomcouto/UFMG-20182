#include "doctest.h"
#include "wizard.h"

TEST_CASE("Testing Construtor"){
    std::vector<Spell *> _spells;
    std::vector<Potions *> _potions;
    std::vector<Artifacts *> _artifacts;
    CHECK_NOTHROW(Wizard *Harry = new Wizard("Harry Potter", 1, 100, 100, 1, 1, 1, "Gryffindor", "Holly wood and Phoenix feathers", "Deer", _spells, _potions, _artifacts));
}
