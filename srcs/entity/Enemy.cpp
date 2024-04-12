/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfdfdfdfd <fdfdfdfd>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:08:25 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/12 22:12:05 by dfdfdfdfd        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "BaseEntity.hpp"

#include <iostream>

Enemy::Enemy() : BaseEntity(), _speed(DEFAULT_SPEED) {}
Enemy::Enemy( int speed, int health, Point position ) : BaseEntity(health, position), _speed(speed) {}
Enemy::Enemy( const Enemy &other ) : BaseEntity(other), _speed(other._speed) {}
Enemy::~Enemy() {}

int Enemy::getSpeed( void ) const {
	return (this->_speed);
}

void Enemy::setSpeed( const int speed ) {
	this->_speed = speed;
}

Enemy &Enemy::operator=( const Enemy &other ) {
	this->_health = other.getHealth();
	this->_position = other.getPosition();
	this->_speed = other._speed;
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const Enemy &instance ) {
	stream << "{Enemy:"
		<< "speed=" << instance.getSpeed()
		<< ",health=" << instance.getHealth()
		<< ",position=" << instance.getPosition()
		<< '}';
	return (stream);
}
