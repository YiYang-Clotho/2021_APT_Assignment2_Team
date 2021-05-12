#ifndef __TEST_PLAYER__
#define __TEST_PLAYER__
#include "../src/Player.h"
#include <iostream>
class TestPlayer {
public:
	TestPlayer() {
		VERIFY(test_playOneTile(), "test_playOneTile");
	}

	bool test_playOneTile();

	void VERIFY(bool result, std::string tag);


};


#endif