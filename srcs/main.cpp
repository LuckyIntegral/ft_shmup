
#include "Game.hpp"
#include <cstddef>
#include <iostream>
#include <ncurses.h>


void	Game::run( void ) {
	size_t steps = 1;

	for (int i = 0; i < 10; ++i) {
		this->spawnEntity();
	}
	this->drawStats();
	this->drawBattle();
	usleep(1000000);
	while (this->_gameStatus == PLAYING) {
		this->keyPressed(getch());
		werase(this->getBattleWin());
		this->updateAll(steps);
		this->drawStats();
		this->drawBattle();
		usleep(10000);// repace this with some other way to control time
		steps++;
    }
}

int main( void ) {
	Game game;

	if (game.init() != 0)
		return (1);
	game.run();
	game.drawEnd();
	game.destroy();
	return (0);
}
