/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyFries.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:20:52 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 02:05:17 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "EnemyFries.hpp"

EnemyFries::EnemyFries() : AEnemy() {}
EnemyFries::EnemyFries( Point position ) : AEnemy(FRIES_HEALTH, position, FRIES_SKIN, FRIES_SPEED) {}
EnemyFries::EnemyFries( const EnemyFries &other ) : AEnemy(other) {}
EnemyFries::~EnemyFries() {}

void	EnemyFries::move( size_t frame ) {
	if (frame % this->_speed == 0) {
		this->setPosition(Point(this->getPosition().getY() + 1, this->getPosition().getX()));
	}
}

void	EnemyFries::shoot( size_t frame ) {
	if (frame % FRIES_SHOOT_RATE == 0) {
		// this->_bullets.push_back(new Bullet(Point(this->getPosition().getY() + 1, this->getPosition().getX())));
	}
}

EnemyFries &EnemyFries::operator=( const EnemyFries &other ) {
	this->_health = other.getHealth();
	this->_position = other.getPosition();
	this->_speed = other._speed;
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const EnemyFries &instance ) {
	stream << "{EnemyFries:"
		<< "speed=" << instance.getSpeed()
		<< ",health=" << instance.getHealth()
		<< ",position=" << instance.getPosition()
		<< '}';
	return (stream);
}
