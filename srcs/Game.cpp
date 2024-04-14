/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:17:11 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 19:02:43 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Game.hpp"

int Game::_spawnRate = 300;

Game::Game() : _entities(), _bullets(), _gameStatus(DEFAULT_GAME_STATUS), _player(Player(DEFAULT_PLAYER_HEALTH, Point(DEFAULT_POSITION_X, DEFAULT_POSITION_Y))), _score(0), _screenHeight(BATTLE_HEIGHT), _screenWidth(SCREEN_WIDTH) {}

Game::~Game() {
	for (auto entity : this->_entities) {
		delete entity;
	}
	for (auto bullet : this->_bullets) {
		delete bullet;
	}
	this->_bullets.clear();
}

void	Game::init( void ) {
	int max_x, max_y;

	setlocale(LC_ALL, "");
	this->setMainWin(initscr());
	curs_set(0);
	noecho(); 				// for ncurses, don't echo any keypresses
	keypad(stdscr, TRUE); 	// for ncurses, enable special keys
	timeout(0); 			// Set timeout for getch to non-blocking mode
	getmaxyx(this->getMainWin(), max_y, max_x);
	if (max_y < (BATTLE_HEIGHT + STATS_HEIGHT) || max_x < SCREEN_WIDTH) {
		endwin();
		throw WrongWindowSizeException();
	}
	this->setStatsWin(subwin(this->getMainWin(), STATS_HEIGHT, SCREEN_WIDTH, 0, 0));
	this->setBattleWin(subwin(this->getMainWin(), BATTLE_HEIGHT, SCREEN_WIDTH, STATS_HEIGHT, 0));
}

void	Game::pauseGame( void ) {
	int key;

	this->setGameStatus(PAUSED);
	timeout(-1);
	mvwprintw(this->getBattleWin(), BATTLE_HEIGHT / 2, SCREEN_WIDTH / 2 - 4, "Paused");
	wrefresh(this->_battleWin);
	while (this->_gameStatus == PAUSED) {
		key = getch();
		if (key == 'p')
			this->setGameStatus(PLAYING);
		else if (key == 'q' || key == 27)
			this->setGameStatus(ABORTED);
	}
	timeout(0);
}

void	Game::drawEnd( void ) {
	WINDOW *endWindow;
	int	winHeight, winWidth;

	start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    winHeight = (BATTLE_HEIGHT + STATS_HEIGHT - 5) / 2;
    winWidth = (SCREEN_WIDTH - 20) / 2;
	endWindow = newwin(5, 20, winHeight, winWidth);
	wbkgd(endWindow, COLOR_PAIR(1));
    wattron(endWindow, A_BOLD);
	if (this->_gameStatus == ABORTED)
		mvwprintw(endWindow, 2, 3, "Game aborted\n");
	else if (this->_gameStatus == OVER)
		mvwprintw(endWindow, 2, 5, "Game over.\n");
    wattroff(endWindow, COLOR_PAIR(2));
    wattroff(endWindow, A_BOLD);
	wrefresh(endWindow);
	usleep(3000000);
	timeout(-1);
	getch();
	delwin(endWindow);
}

void	Game::destroy( void ) {
	delwin(this->_battleWin);
	delwin(this->_statsWin);
	endwin();
}

void	Game::keyPressed( int key ) {
	if (key == KEY_UP) {
		this->_player.goUp(PLAYER_SPEED);
	} else if (key == KEY_DOWN) {
		this->_player.goDown(PLAYER_SPEED);
	} else if (key == KEY_LEFT) {
		this->_player.goLeft(PLAYER_SPEED * 2);
	} else if (key == KEY_RIGHT) {
		this->_player.goRight(PLAYER_SPEED * 2);
	} else if (key == 'q' || key == 27) {
		this->setGameStatus(ABORTED);
	} else if (key == 'p') {
		this->pauseGame();
	} else if (key == ' ') {
		this->_player.shoot();
	}
}

void	Game::advanceEnemies( size_t frame ) {
	for (auto entity : this->_entities) {
		if (entity->getPosition().getY() > (BATTLE_HEIGHT - 3)) {
			this->setGameStatus(OVER);
			break ;
		}
		entity->move(frame);
	}
}

void	Game::checkBulletVsEnemy( void ) {
	bool bulletHit = false;
	for (auto bullet : this->_player.getBullets()) {
		for (size_t i = 0; i < this->_entities.size(); i++) {
			if (bullet->getPosition() == this->_entities[i]->getPosition()){
				auto entity = this->_entities[i];
				this->_entities.erase(this->_entities.begin() + i);
				i--;
				delete entity;
				this->_score += 10;
				bulletHit = true;
			}
		}
		if (bulletHit) {
			bullet->setPosition(Point(0, 0));
			bulletHit = false;
		}
	}
}

void	Game::checkBulletVsPlayer( void ) {
	for (auto bullet : this->getBullets()) {
		if (bullet->getPosition() == this->_player.getPosition()){
			this->_player.setHealth(this->_player.getHealth() - 1);
			if (this->_player.getHealth() == 0) {
				this->setGameStatus(OVER);
			}
			bullet->setPosition(Point(0, 0));
		}
	}
}

void	Game::updateAll( size_t frame ) {
	this->shootRandom(frame);
	this->_player.refreshBullets(frame);
	this->refreshBullets(frame);
	this->advanceEnemies(frame);
	this->checkBulletVsEnemy();
	this->checkBulletVsPlayer();
	for (auto entity : this->_entities) {
		if (entity->getPosition() == this->_player.getPosition()) {
			this->setGameStatus(OVER);
			break ;
		}
	}
	if (frame % 100 == 0) {
		Game::_spawnRate -= 10;
		if (Game::_spawnRate < 100) {
			Game::_spawnRate = 100;
		}
	}
	if (frame % Game::_spawnRate == 0) {
		this->spawnEntity();
	}
	// check if projectiles hit projectiles
}

void	Game::spawnEntity( void ) {
	static int rand = time(NULL) % 27;

	BaseEntity *entity = nullptr;
	Point position(rand % 3 + 1, (rand % (SCREEN_WIDTH / 2 - 1) * 2) + 1);
	if (rand % 6 == 0)
		entity = new EnemyPizza(position);
	else if (rand % 6 == 1)
		entity = new EnemyFries(position);
	else if (rand % 6 == 2)
		entity = new EnemyHotDog(position);
	else if (rand % 6 == 3)
		entity = new EnemyBurger(position);
	else if (rand % 6 == 4)
		entity = new EnemyLolipop(position);
	else
		entity = new EnemyPizza(position);
	this->_entities.push_back(entity);
	rand = (rand * 37 + 15) * 15 % 127;
}

void	Game::drawBattle( void ) {
	box(this->_battleWin, '|', '-');
	for (auto entity : this->_entities) {
		this->drawEntity(entity);
	}
	this->drawEntity(&(this->_player));
	for (auto bullet : this->_player.getBullets()) {
		this->drawEntity(bullet);
	}
	for (auto bullet : this->getBullets()) {
		this->drawEntity(bullet);
	}
	wrefresh(this->_battleWin);
}

void	Game::drawStats( void ) {
	box(this->_statsWin, '|', '-');
	mvwprintw(this->_statsWin, 1, 6, "🍔🍟🌭🍦🍭🍕 Eat em up! 🍕🍭🍦🌭🍟🍔");
	mvwprintw(this->_statsWin, 2, SCREEN_WIDTH / 2 - 6, "Score : %05d", this->_score);
	mvwprintw(this->_statsWin, 3, SCREEN_WIDTH / 2 - 6, "Health: ");
	for (int i = 0; i < DEFAULT_PLAYER_HEALTH; i++) {
		if (i < this->_player.getHealth())
			mvwprintw(this->_statsWin, 3, SCREEN_WIDTH / 2 + 2 + (i * 2), "❤️");
		else
			mvwprintw(this->_statsWin, 3, SCREEN_WIDTH / 2 + 2 + (i * 2), "  ");
	}
	wrefresh(this->_statsWin);
}

void Game::drawEntity( BaseEntity *entity ) {
	mvwprintw(this->getBattleWin(), entity->getPosition().getY(),
		entity->getPosition().getX(), "%s", entity->getSkin().c_str());
}

void Game::addEntity( BaseEntity *entity ) {
	this->_entities.push_back(entity);
}

GameStatus Game::getGameStatus( void ) const {
	return (this->_gameStatus);
}

void Game::setGameStatus( const GameStatus gameStatus ) {
	this->_gameStatus = gameStatus;
}

WINDOW *Game::getMainWin( void ) const {
	return (this->_mainWin);
}

void Game::setMainWin( WINDOW *mainWin ) {
	this->_mainWin = mainWin;
}

WINDOW *Game::getStatsWin( void ) const {
	return (this->_statsWin);
}

void Game::setStatsWin( WINDOW *statsWin ) {
	this->_statsWin = statsWin;
}

WINDOW *Game::getBattleWin( void ) const {
	return (this->_battleWin);
}

void Game::setBattleWin( WINDOW *battleWin ) {
	this->_battleWin = battleWin;
}

std::vector<Bullet *>	Game::getBullets( void ) {
	return (this->_bullets);
}

void 	Game::refreshBullets( int frame ) {
	for (auto bullet : this->_bullets) {
		bullet->move(frame);
	}
	for (auto bullet : this->_bullets) {
		if (bullet->getPosition().getY() >= BATTLE_HEIGHT) {
			auto bulletIt = std::find(this->_bullets.begin(), this->_bullets.end(), bullet);
			delete *bulletIt;
			this->_bullets.erase(std::remove(this->_bullets.begin(), this->_bullets.end(), bullet), this->_bullets.end());
		}
	}
}

void	Game::shootRandom( int frame ) {
	if (frame % 100 == 0) {
		int rand = time(NULL);
		rand = rand % this->_entities.size();
		this->_bullets.push_back(new Bullet(this->_entities[rand]->getPosition(), t_bulletType::ENEMY, ENEMY_BULLET_SKIN, ENEMY_BULLET_SPEED));
	}
}

const char *Game::WrongWindowSizeException::what() const throw() {
	return ("Window size is too small");
}
