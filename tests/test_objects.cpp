#include "doctest.h"
#include "objects.h"

TEST_CASE("Testing Construtor"){
	CHECK_NOTHROW(Object(2, "Amortentia", 6, -10, -40, 3, 1, 2));
}

TEST_CASE("Testing Getters"){
	Object *LovePotion = new Object(2, "Amortentia", 6, -10, -40, 3, 1, 2);

		std::string name = LovePotion->get_name();
			CHECK_EQ(name, "Amortentia");
	
		int level = LovePotion->get_level();
			CHECK(level == 6);
	
		int time = LovePotion->getDuration();
			CHECK(time == 2);
	
		int hp_effect = LovePotion->get_hp_effect();	
			CHECK(hp_effect == -10);

		Stats test = {6, -10, -40, 3, 1, 2};
			CHECK_EQ(LovePotion->getEffectsStats().level, 6);
			CHECK_EQ(LovePotion->getEffectsStats().hp, -10);
			CHECK_EQ(LovePotion->getEffectsStats().mp, -40);
			CHECK_EQ(LovePotion->getEffectsStats().strenght, 3);
			CHECK_EQ(LovePotion->getEffectsStats().constitution, 1);
			CHECK_EQ(LovePotion->getEffectsStats().dexterity, 2);
			
	delete LovePotion;
}
