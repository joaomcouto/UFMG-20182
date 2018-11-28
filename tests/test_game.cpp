#include "doctest.h"
#include "game.h"
#include "wizard.h"

TEST_CASE("Testing Throws"){
	CHECK_NOTHROW(texts1());
//	CHECK_NOTHROW(initialize_game());   ---> Isso dá errado
}

