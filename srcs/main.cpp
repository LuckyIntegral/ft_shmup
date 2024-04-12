
#include "Game.hpp"
#include <ncurses.h>


void	Game::run( void ) {
	WINDOW *local_win = initscr(); // for ncurses, initialize the screen
	noecho(); // for ncurses, don't echo any keypresses
	keypad(stdscr, TRUE); // for ncurses, enable special keys

	box(local_win, 0 , 0);		/* 0, 0 gives default characters
					 * for the vertical and horizontal
					 * lines			*/
	wborder(local_win, '|', '|', '-', '-', '+', '+', '+', '+');
	wrefresh(local_win);

	while (this->_isFinished == false) {
        int val = getch(); // for ncurses, get the next character typed
		this->keyPressed(val);
        printw("PEW PEW %d %d %d!\n", val, this->_player.getPosition().getX(), this->_player.getPosition().getY());
        refresh(); // for ncurses, refresh the screen to match what we've written
    }

    endwin(); // for ncurses, cleanup and close the screen
}

int main( void ) {
	Game game;
	game.init();
	game.run();
	return (0);
}
