#include "doctest.h"
#include "spells.h"

TEST_CASE ("Testing Construtor"){
    Spell *spells= new Spell(2, "Expelliarmus", 1, -30, -40, -2, -1, 0);
    CHECK_NOTHROW(spells);
}
TEST_CASE ("Testing Getters and Setters"){
    Spell *spells= new Spell(2, "Expelliarmus", 1, -30, -40, -2, -1, 0);
    Stats test = {1, -30, -40, -2, -1, 0};

    CHECK_EQ(spells->getDuration(), 2);
    CHECK_EQ(spells->get_name(), "Expelliarmus");
    CHECK_EQ(spells->get_level(), 1);
    CHECK_EQ(spells->get_hp_dmg(), -30);
    CHECK_EQ(spells->get_mp_dmg(), -40);
    CHECK_EQ(spells->get_strenght_dmg(), -2);
    CHECK_EQ(spells->get_constituion_dmg(), -1);
    CHECK_EQ(spells->get_dexterity_dmg(), 0);

    CHECK_EQ(spells->getDamageStats().level, test.level);
    CHECK_EQ(spells->getDamageStats().hp, test.hp);
    CHECK_EQ(spells->getDamageStats().mp, test.mp);
    CHECK_EQ(spells->getDamageStats().strenght, test.strenght);
    CHECK_EQ(spells->getDamageStats().dexterity, test.dexterity);
    CHECK_EQ(spells->getDamageStats().constitution, test.constitution);

    delete spells;
}