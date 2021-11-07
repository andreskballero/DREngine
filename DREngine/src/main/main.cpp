#include "../MainGame/MainGame.h"
#include "../Sprite/Sprite.h"

#include <cstdlib>

int main(int argc, char* argv[])
{
	maingame::MainGame mainGame;
	mainGame.run();

	return EXIT_SUCCESS;
}