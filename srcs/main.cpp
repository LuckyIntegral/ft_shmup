
#include "Game.hpp"
#include <cstddef>
#include <iostream>
#include <ncurses.h>
#include <signal.h>

int 	sigResize = 0;

void	resizeHandler(int sig) {
	(void)sig;
	sigResize = 1;
}

void	Game::run( void ) {
	size_t steps = 1;

	signal(SIGWINCH, resizeHandler);
	for (int i = 0; i < 10; ++i) {
		this->spawnEntity();
	}
	this->drawStats(steps);
	this->drawBattle();
	//usleep(1000000);
	while (this->_gameStatus == PLAYING && sigResize == 0) {
		this->keyPressed(getch());
		werase(this->getBattleWin());
		this->updateAll(steps);
		this->drawStats(steps);
		this->drawBattle();
		usleep(10000);// repace this with some other way to control time
		steps++;
    }
}

int main( void ) {
	Game game;

	try {
		game.init();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	game.run();
	game.drawEnd();
	game.destroy();
	return (0);
}
