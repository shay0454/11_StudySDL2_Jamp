#include<iostream>
#include<SDL.h>
#include "Vector2.h"
#include "Game.h"

int main(int argc, char** argv) {
	Game game;
	bool success = game.Initialzie();
	if (success) {
		game.RunLoop();
	}
	game.Shutdown();
	return 0;
}