/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyPizza.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:20:52 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 02:06:23 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "EnemyPizza.hpp"

EnemyPizza::EnemyPizza() : AEnemy() {}
EnemyPizza::EnemyPizza( Point position ) : AEnemy(PIZZA_HEALTH, position, PIZZA_SKIN, PIZZA_SPEED) {}
EnemyPizza::EnemyPizza( const EnemyPizza &other ) : AEnemy(other) {}
EnemyPizza::~EnemyPizza() {}

void	EnemyPizza::move( size_t frame ) {
	if (frame % this->_speed == 0) {
		this->setPosition(Point(this->getPosition().getY() + 1, this->getPosition().getX()));
	}
}

void	EnemyPizza::shoot( size_t frame ) {
	if (frame % PIZZA_SHOOT_RATE == 0) {
		// this->_bullets.push_back(new Bullet(Point(this->getPosition().getY() + 1, this->getPosition().getX())));
	}
}

EnemyPizza &EnemyPizza::operator=( const EnemyPizza &other ) {
	this->_health = other.getHealth();
	this->_position = other.getPosition();
	this->_speed = other._speed;
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const EnemyPizza &instance ) {
	stream << "{EnemyPizza:"
		<< "speed=" << instance.getSpeed()
		<< ",health=" << instance.getHealth()
		<< ",position=" << instance.getPosition()
		<< '}';
	return (stream);
}
