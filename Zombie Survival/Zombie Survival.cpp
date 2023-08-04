// This file runs the game

#include "game.h"

int main()
{
	Graphics graphics;

	Game game(&graphics); // Instansiate the "game" object

	game.run(); // Call the "run()" function

	return 0; // A good programing practice
}