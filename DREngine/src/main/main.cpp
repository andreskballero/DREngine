#include <cstdlib>

#include "../MainGame/MainGame.h"

int main(int argc, char* argv[])
{
	maingame::MainGame mainGame;
	mainGame.run();

	return EXIT_SUCCESS;
}