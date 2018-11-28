#include "doctest.h"
#include "potions.h"

TEST_CASE("Testing Constuctor"){
	CHECK_NOTHROW(Potions(2, "Polyjuice", 3, 0, -20, 2, 1, 1, 3));
}

TEST_CASE("Testing Getter and Setters"){
	Potions *PolyJuice = new Potions(2, "Polyjuice", 3, 0, -20, 2, 1, 1, 3);

	int qnt = PolyJuice->get_quant();
		CHECK(qnt == 3);
		
	PolyJuice->set_quant(1);
		qnt = PolyJuice->get_quant();
		CHECK(qnt == 4);

	delete PolyJuice;
}

