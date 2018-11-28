#include "doctest.h"
#include "artefacts.h"

TEST_CASE ("Testing Construtor"){
	CHECK_NOTHROW(Artifacts(2, "Deluminator", 1, 0, 10, 0, 1, 1, 1, true, "Removes light from an area and restores it with a click!"));
}

TEST_CASE ("Testing Getters and Setters"){
	Artifacts *Put_Outer = new Artifacts(2, "Deluminator", 1, 0, 10, 0, 1, 1, 1, true, "Removes light from an area and restores it with a click!");

	std::string Text = Put_Outer->getSpecialEffect();
		CHECK_EQ(Tet, "Removes light from an area and restores it with a click!");

	int exist = Put_Outer->get_exist();
		CHECK_EQ(exist,true);
		
	Put_Outer->set_exist();
	exist = Put_Outer->get_exist();
		CHECK_EQ(exist,false);

	delete Put_Outer;
	
}
