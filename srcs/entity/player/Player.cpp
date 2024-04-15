/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:09:10 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 23:36:03 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Game.hpp"
#include "Player.hpp"

#include <algorithm>
#include <iostream>
#include <ncurses.h>

Player::Player() : _bullets() {}
Player::Player( int health, Point position ) : BaseEntity(health, position, "🎾", 1), _bullets() {}
Player::~Player() {
	for (auto bullet : this->_bullets) {
		delete bullet;
	}
	this->_bullets.clear();
}

void	Player::shoot( void ) {
	this->_bullets.push_back(new Bullet(this->getPosition(), t_bulletType::PLAYER, PLAYER_BULLET_SPEED));
}

void	Player::goUp( int steps ) {
	if (this->getPosition().getY() - steps <= 0)
		return ;
	this->setPosition(Point(this->getPosition().getY() - steps, this->getPosition().getX()));
}

void	Player::goDown( int steps ) {
	if (this->getPosition().getY() + steps >= BATTLE_HEIGHT - 1)
		return ;
	this->setPosition(Point(this->getPosition().getY() + steps, this->getPosition().getX()));
}

void	Player::goLeft( int steps ) {
	if (this->getPosition().getX() - steps <= 0)
		return ;
	this->setPosition(Point(this->getPosition().getY(), this->getPosition().getX() - steps));
}

void	Player::goRight( int steps ) {
	if (this->getPosition().getX() + steps >= SCREEN_WIDTH - 2)
		return ;
	this->setPosition(Point(this->getPosition().getY(), this->getPosition().getX() + steps));
}

std::vector<Bullet *>	Player::getBullets( void ) {
	return (this->_bullets);
}

void 	Player::refreshBullets( int frame ) {
	for (auto bullet : this->_bullets) {
		bullet->move(frame);
	}
	for (auto bullet : this->_bullets) {
		if (bullet->getPosition().getY() <= 0) {
			auto bulletIt = std::find(this->_bullets.begin(), this->_bullets.end(), bullet);
			delete *bulletIt;
			this->_bullets.erase(std::remove(this->_bullets.begin(), this->_bullets.end(), bullet), this->_bullets.end());
		}
	}
}

void	Player::move( size_t ) {}

std::ostream	&operator<<( std::ostream &stream, const Player &instance ) {
	stream << "{Player:{"
		<< "health=" << instance.getHealth()
		<< ",position=" << instance.getPosition()
		<< "}}";
	return (stream);
}
