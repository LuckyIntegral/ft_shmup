
#include "Game.hpp"
#include <cstddef>
#include <iostream>
#include <ncurses.h>
#include <unistd.h>


void	Game::run( void ) {
	int max_x, max_y;
	size_t steps = 1;
	setlocale(LC_ALL, "");
	this->setMainWin(initscr());
	curs_set(0);
	noecho(); // for ncurses, don't echo any keypresses
	keypad(stdscr, TRUE); // for ncurses, enable special keys
    timeout(0); // Set timeout for getch to non-blocking mode
	// noblock(stdscr); // for ncurses, don't block when waiting for input

	getmaxyx(this->getMainWin(), max_y, max_x);	// get current dimensions of  terminal
	if (max_y < (BATTLE_HEIGHT + STATS_HEIGHT) || max_x < SCREEN_WIDTH) {
		endwin();
		std::cerr << "Terminal too small" << std::endl;
		return ;
	}
	this->setStatsWin(subwin(this->getMainWin(), STATS_HEIGHT, SCREEN_WIDTH, 0, 0));
	box(this->getStatsWin(), '|', '-');
	mvwprintw(this->getStatsWin(), 1, 1, "~FT_SHMUP~");
	this->setBattleWin(subwin(this->getMainWin(), BATTLE_HEIGHT, SCREEN_WIDTH, STATS_HEIGHT, 0));

	this->drawStats();
	this->drawBattle();
	//wrefresh(this->getBattleWin());
	usleep(1000000);

	while (this->_gameStatus == PLAYING) {
        //int val = getch(); // for ncurses, get the next character typed
		//clear();
		werase(this->getBattleWin());

		this->keyPressed(getch()); // TODO add multiple keypresses
		this->updateAll(steps);
		this->drawStats();
		this->drawBattle();
		//wrefresh(this->getBattleWin());
		usleep(10000);// repace this with some other way to control time
		steps++;
    }
	if (this->_gameStatus == ABORTED)
		mvwprintw(this->getBattleWin(), 0, 0, "Game aborted\n");
	else if (this->_gameStatus == LOST)
		mvwprintw(this->getBattleWin(), 0, 0, "Game over\n");
	else if (this->_gameStatus == WON)
		mvwprintw(this->getBattleWin(), 0, 0, "You won!\n");
	wrefresh(this->getBattleWin());
	timeout(10000);
	getch();

	delwin(this->getStatsWin());
	delwin(this->getBattleWin());

    endwin(); // for ncurses, cleanup and close the screen
}

int main( void ) {
	Game game;
	game.init();
	game.run();
	return (0);
}
