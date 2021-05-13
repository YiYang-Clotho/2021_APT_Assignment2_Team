#include "TestPlayer.h"

bool TestPlayer::test_playOneTile() {
	Player* player = new Player("Gao");
	return true;
}

void TestPlayer::VERIFY(bool result, std::string tag) {
	std::cout << "\t* TEST: tag:[";
	if (result) {
		std::cout << "Passed." << std::endl;
	}
	else {
		std::cout << "Failed!" << std::endl;

	}
}
