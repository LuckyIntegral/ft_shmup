/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyIceCream.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:20:52 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 02:05:30 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "EnemyIceCream.hpp"

EnemyIceCream::EnemyIceCream() : AEnemy() {}
EnemyIceCream::EnemyIceCream( Point position ) : AEnemy(ICE_CREAM_HEALTH, position, ICE_CREAM_SKIN, ICE_CREAM_SPEED) {}
EnemyIceCream::EnemyIceCream( const EnemyIceCream &other ) : AEnemy(other) {}
EnemyIceCream::~EnemyIceCream() {}

void	EnemyIceCream::move( size_t frame ) {
	if (frame % this->_speed == 0) {
		this->setPosition(Point(this->getPosition().getY() + 1, this->getPosition().getX()));
	}
}

void	EnemyIceCream::shoot( size_t frame ) {
	if (frame % ICE_CREAM_SHOOT_RATE == 0) {
		// this->_bullets.push_back(new Bullet(Point(this->getPosition().getY() + 1, this->getPosition().getX())));
	}
}

EnemyIceCream &EnemyIceCream::operator=( const EnemyIceCream &other ) {
	this->_health = other.getHealth();
	this->_position = other.getPosition();
	this->_speed = other._speed;
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const EnemyIceCream &instance ) {
	stream << "{EnemyIceCream:"
		<< "speed=" << instance.getSpeed()
		<< ",health=" << instance.getHealth()
		<< ",position=" << instance.getPosition()
		<< '}';
	return (stream);
}
