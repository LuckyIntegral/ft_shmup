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
#include "BaseEntity.hpp"

#include <iostream>

EnemyBurger::EnemyBurger() : BaseEntity() {}
EnemyBurger::EnemyBurger( Point position ) : BaseEntity(BURGER_HEALTH, position, BURGER_SKIN, BURGER_SPEED) {}
EnemyBurger::EnemyBurger( const EnemyBurger &other ) : BaseEntity(other) {}
EnemyBurger::~EnemyBurger() {}

void	EnemyBurger::move( size_t frame ) {
	if (frame % this->_speed == 0) {
		this->setPosition(Point(this->getPosition().getY() + 1, this->getPosition().getX()));
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
