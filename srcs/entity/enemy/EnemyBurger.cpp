/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyBurger.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:08:25 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/13 19:40:36 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnemyBurger.hpp"

EnemyBurger::EnemyBurger() : AEnemy() {}
EnemyBurger::EnemyBurger( Point position ) : AEnemy(BURGER_HEALTH, position, BURGER_SKIN, BURGER_SPEED) {}
EnemyBurger::EnemyBurger( const EnemyBurger &other ) : AEnemy(other) {}
EnemyBurger::~EnemyBurger() {}

void	EnemyBurger::move( size_t frame ) {
	if (frame % this->_speed == 0) {
		this->setPosition(Point(this->getPosition().getY() + 1, this->getPosition().getX()));
	}
}

void	EnemyBurger::shoot( size_t frame ) {
	if (frame % BURGER_BULLET_RATE == 0) {
		// shoot bullet
	}
}

EnemyBurger &EnemyBurger::operator=( const EnemyBurger &other ) {
	this->_health = other.getHealth();
	this->_position = other.getPosition();
	this->_speed = other._speed;
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const EnemyBurger &instance ) {
	stream << "{EnemyBurger:"
		<< "speed=" << instance.getSpeed()
		<< ",health=" << instance.getHealth()
		<< ",position=" << instance.getPosition()
		<< '}';
	return (stream);
}
