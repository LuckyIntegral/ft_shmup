/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfdfdfdfd <fdfdfdfd>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:17:11 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/12 23:40:24 by dfdfdfdfd        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

#include <iostream>

Game::Game() : _entities(), _isFinished(DEFAULT_IS_FINISHED), _isWon(DEFAULT_IS_WON), _score(0), _screenHeight(SCREEN_HEIGHT), _screenWidth(SCREEN_WIDTH) {
	this->_player = Player(DEFAULT_PLAYER_HEALTH, Point(DEFAULT_POSITION_X, DEFAULT_POSITION_Y));
}

Game::~Game() {
	for (auto entity : this->_entities) {
		delete entity;
	}
}

void	Game::init( void ) {
	this->addEntity(new BaseEntity(1, Point(10, 10)));
	this->addEntity(new BaseEntity(2, Point(20, 20)));
	this->addEntity(new BaseEntity(3, Point(30, 30)));
	this->addEntity(new BaseEntity(4, Point(40, 40)));
	this->addEntity(new BaseEntity(5, Point(50, 50)));
}

void	Game::keyPressed( int key ) {
	if (key == KEY_UP) {
		if (this->_player.getPosition().getY() - PLAYER_SPEED > 10) {
			this->_player.goUp(PLAYER_SPEED);
		}
	} else if (key == KEY_DOWN) {
		if (this->_player.getPosition().getY() + PLAYER_SPEED < SCREEN_HEIGHT - 10) {
			this->_player.goDown(PLAYER_SPEED);
		}
	} else if (key == KEY_LEFT) {
		if (this->_player.getPosition().getX() - PLAYER_SPEED > 10) {
			this->_player.goLeft(PLAYER_SPEED);
		}
	} else if (key == KEY_RIGHT) {
		if (this->_player.getPosition().getX() + PLAYER_SPEED < SCREEN_WIDTH - 10) {
			this->_player.goRight(PLAYER_SPEED);
		}
	} else if (key == 'q') {
		this->setIsfinished(true);
	} else {
		std::cout << "Key pressed: " << key << " ignored at the time" << std::endl;
	}
}

void Game::printEntities( void ) const {
	for (auto entity : this->_entities) {
		std::cout << *entity << std::endl;
	}
}

void Game::addEntity( BaseEntity *entity ) {
	this->_entities.push_back(entity);
}

bool Game::getIsfinished( void ) const {
	return (this->_isFinished);
}

void Game::setIsfinished( const bool isFinished ) {
	this->_isFinished = isFinished;
}

bool Game::getIswon( void ) const {
	return (this->_isWon);
}

void Game::setIswon( const bool isWon ) {
	this->_isWon = isWon;
}
