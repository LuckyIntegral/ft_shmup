/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyHotDog.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:20:52 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 02:05:24 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "EnemyHotDog.hpp"

EnemyHotDog::EnemyHotDog() : AEnemy() {}
EnemyHotDog::EnemyHotDog( Point position ) : AEnemy(HOT_DOG_HEALTH, position, HOT_DOG_SKIN, HOT_DOG_SPEED) {}
EnemyHotDog::EnemyHotDog( const EnemyHotDog &other ) : AEnemy(other) {}
EnemyHotDog::~EnemyHotDog() {}

void	EnemyHotDog::move( size_t frame ) {
	if (frame % this->_speed == 0) {
		this->setPosition(Point(this->getPosition().getY() + 1, this->getPosition().getX()));
	}
}

void	EnemyHotDog::shoot( size_t frame ) {
	if (frame % HOT_DOG_SHOOT_RATE == 0) {
		// this->_bullets.push_back(new Bullet(Point(this->getPosition().getY() + 1, this->getPosition().getX())));
	}
}

EnemyHotDog &EnemyHotDog::operator=( const EnemyHotDog &other ) {
	this->_health = other.getHealth();
	this->_position = other.getPosition();
	this->_speed = other._speed;
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const EnemyHotDog &instance ) {
	stream << "{EnemyHotDog:"
		<< "speed=" << instance.getSpeed()
		<< ",health=" << instance.getHealth()
		<< ",position=" << instance.getPosition()
		<< '}';
	return (stream);
}
