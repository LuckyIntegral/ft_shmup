/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:52:09 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 19:45:55 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy() : BaseEntity(), _scorePoints() {}

Enemy::Enemy( int health, Point position, std::string skin,
	int speed, int shootRate, int shootSpeed, int scorePoints )
		: BaseEntity(health, position, skin, speed),
		_shootRate(shootRate), _shootSpeed(shootSpeed), _scorePoints(scorePoints) {}

Enemy::Enemy( const Enemy &instance )
		: BaseEntity(instance), _scorePoints(instance.getScorePoints()) {}

Enemy::~Enemy() {}

void	Enemy::shoot( size_t frame ) {
	(void)frame;
}

int	Enemy::getShootRate( void ) const {
	return (this->_shootRate);
}

void	Enemy::setShootRate( const int shootRate ) {
	this->_shootRate = shootRate;
}

int	Enemy::getShootSpeed( void ) const {
	return (this->_shootSpeed);
}

void	Enemy::setShootSpeed( const int shootSpeed ) {
	this->_shootSpeed = shootSpeed;
}

int	Enemy::getScorePoints( void ) const {
	return (this->_scorePoints);
}

void	Enemy::move( size_t frame ) {
	if (frame % this->_speed == 0) {
		this->setPosition(Point(this->getPosition().getY() + 1, this->getPosition().getX()));
	}
}

Enemy &Enemy::operator=( const Enemy &instance ) {
	this->_health = instance._health;
	this->_position = instance._position;
	this->_skin = instance._skin;
	this->_speed = instance._speed;
	this->_shootRate = instance._shootRate;
	this->_shootSpeed = instance._shootSpeed;
	return (*this);
}
