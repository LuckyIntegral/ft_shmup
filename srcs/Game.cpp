/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:17:11 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 01:42:12 by vfrants          ###   ########.fr       */
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
}

void	Game::init( void ) {
	for (int i = 0; i < 10; ++i) {
		this->spawnEntity();
	}
}

void	Game::keyPressed( int key ) {
	if (key == KEY_UP) {
		this->_player.goUp(PLAYER_SPEED);
	} else if (key == KEY_DOWN) {
		this->_player.goDown(PLAYER_SPEED);
	} else if (key == KEY_LEFT) {
		this->_player.goLeft(PLAYER_SPEED);
	} else if (key == KEY_RIGHT) {
		this->_player.goRight(PLAYER_SPEED);
	} else if (key == 'q' || key == 27) {
		this->setGameStatus(ABORTED);
	} else if (key == ' ') {
		this->_player.shoot();
	}
}

void	Game::updateAll( size_t frame ) {

	this->_player.refreshBullets(frame);
	for (auto entity : this->_entities) {
		if (entity->getPosition().getY() > BATTLE_HEIGHT - 1) {
			this->setGameStatus(LOST);
			break ;
		}
		entity->move(frame);
	}
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
	for (auto entity : this->_entities) {
		if (entity->getPosition() == this->_player.getPosition()) {
			this->setGameStatus(LOST);
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

	// check if EnemyBurger-projectiles hit player
	// check if projectiles hit projectiles
}

void	Game::spawnEntity( void ) {
	static int rand = time(NULL);
	rand = rand % (SCREEN_WIDTH - 2) + 1;

	BaseEntity *entity = nullptr;
	if (rand % 6 == 0)
		entity = new EnemyPizza(Point(rand % 3 + 1, rand));
	else if (rand % 6 == 1)
		entity = new EnemyFries(Point(rand % 3 + 1, rand));
	else if (rand % 6 == 2)
		entity = new EnemyHotDog(Point(rand % 3 + 1, rand));
	else if (rand % 6 == 3)
		entity = new EnemyBurger(Point(rand % 3 + 1, rand));
	else if (rand % 6 == 4)
		entity = new EnemyLolipop(Point(rand % 3 + 1, rand));
	else
		entity = new EnemyPizza(Point(rand % 3 + 1, rand));
	this->_entities.push_back(entity);
	rand *= 37;
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
	wrefresh(this->_battleWin);
}

void	Game::drawStats( void ) {
	box(this->_statsWin, '|', '-');
	mvwprintw(this->_statsWin, 2, 1, "Score: %d", this->_score);
	mvwprintw(this->_statsWin, 3, 1, "Health: %d", this->_player.getHealth());
	wrefresh(this->_statsWin);
}

void Game::drawEntity( BaseEntity *entity ) {
	mvwprintw(this->getBattleWin(), entity->getPosition().getY(), entity->getPosition().getX(), "%s", entity->getSkin().c_str());	// TODO does not get printed right
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
