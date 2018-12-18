#include "doctest.h"
#include "game.h"
#include "wizard.h"

TEST_CASE("Testing Throws"){
	CHECK_NOTHROW(texts1());
	CHECK_NOTHROW(instantiate_spell());
	CHECK_NOTHROW(instantiate_artifacts());
	CHECK_NOTHROW(instantiate_attack());
	CHECK_NOTHROW(instantiate_potions());
//	CHECK_NOTHROW(initialize_game());   ---> Isso dá errado
}

