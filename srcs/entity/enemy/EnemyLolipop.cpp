/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyLolipop.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:20:52 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 02:06:17 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "EnemyLolipop.hpp"

EnemyLolipop::EnemyLolipop() : AEnemy() {}
EnemyLolipop::EnemyLolipop( Point position ) : AEnemy(LOLI_POP_HEALTH, position, LOLI_POP_SKIN, LOLI_POP_SPEED) {}
EnemyLolipop::EnemyLolipop( const EnemyLolipop &other ) : AEnemy(other) {}
EnemyLolipop::~EnemyLolipop() {}

void	EnemyLolipop::move( size_t frame ) {
	if (frame % this->_speed == 0) {
		this->setPosition(Point(this->getPosition().getY() + 1, this->getPosition().getX()));
	}
}

void	EnemyLolipop::shoot( size_t frame ) {
	if (frame % LOLI_POP_BULLET_RATE == 0) {
		// shoot
	}
}

EnemyLolipop &EnemyLolipop::operator=( const EnemyLolipop &other ) {
	this->_health = other.getHealth();
	this->_position = other.getPosition();
	this->_speed = other._speed;
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const EnemyLolipop &instance ) {
	stream << "{EnemyLolipop:"
		<< "speed=" << instance.getSpeed()
		<< ",health=" << instance.getHealth()
		<< ",position=" << instance.getPosition()
		<< '}';
	return (stream);
}
