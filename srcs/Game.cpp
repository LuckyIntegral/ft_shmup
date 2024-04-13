/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:17:11 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/13 17:36:58 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

#include <iostream>

Game::Game() : _entities(), _gameStatus(DEFAULT_GAME_STATUS), _score(0), _screenHeight(BATTLE_HEIGHT), _screenWidth(SCREEN_WIDTH) {
	this->_player = Player(DEFAULT_PLAYER_HEALTH, Point(DEFAULT_POSITION_X, DEFAULT_POSITION_Y));
}

Game::~Game() {
	for (auto entity : this->_entities) {
		delete entity;
	}
}

void	Game::init( void ) {
	this->addEntity(new BaseEntity(1, Point(1, 1)));
	this->addEntity(new BaseEntity(2, Point(1, 3)));
	this->addEntity(new BaseEntity(3, Point(1, 5)));
	this->addEntity(new BaseEntity(4, Point(1, 7)));
	this->addEntity(new BaseEntity(5, Point(1, 9)));
}

void	Game::keyPressed( int key ) {
	if (key == KEY_UP) {
		if (this->_player.getPosition().getY() - PLAYER_SPEED > STATS_HEIGHT) {
			this->_player.goUp(PLAYER_SPEED);
		}
	} else if (key == KEY_DOWN) {
		if (this->_player.getPosition().getY() + PLAYER_SPEED < STATS_HEIGHT + BATTLE_HEIGHT - 1) {
			this->_player.goDown(PLAYER_SPEED);
		}
	} else if (key == KEY_LEFT) {
		if (this->_player.getPosition().getX() - PLAYER_SPEED > 0) {
			this->_player.goLeft(PLAYER_SPEED);
		}
	} else if (key == KEY_RIGHT) {
		if (this->_player.getPosition().getX() + PLAYER_SPEED < SCREEN_WIDTH - 1) {
			this->_player.goRight(PLAYER_SPEED);
		}
	} else if (key == 'q' || key == 27) {
		this->setGameStatus(ABORTED);
	}
	// } else {
	// 	std::cout << "Key pressed: " << key << " ignored at the time" << std::endl;
	// }
}

void	Game::updateAll( void ) {
	for (auto entity : this->_entities) {
		if (entity->getPosition().getY() > BATTLE_HEIGHT - 1) {
			this->setGameStatus(LOST);
			break ;
		}
		entity->setPosition(Point(entity->getPosition().getY() + 1, entity->getPosition().getX()));
	}
	// update projectiles...
	// check if player-projectiles hit enemies
	// check if enemy-projectiles hit player
	// check if projectiles hit projectiles
}

void	Game::drawBattle( void ) const {
	box(this->_battleWin, '|', '-');
	for (auto entity : this->_entities) {
		entity->draw(this->_battleWin);
	}
	this->_player.draw(this->_battleWin);
	wrefresh(this->_battleWin);
}

void	Game::drawStats( void ) const {
	box(this->_statsWin, '|', '-');
	mvwprintw(this->_statsWin, 2, 1, "Score: %d", this->_score);
	mvwprintw(this->_statsWin, 3, 1, "Health: %d", this->_player.getHealth());
	wrefresh(this->_statsWin);
}

void Game::printEntities( void ) const {
	for (auto entity : this->_entities) {
		std::cout << *entity << std::endl;
	}
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
