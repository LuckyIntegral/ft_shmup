/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseEntity.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:07:11 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 19:30:18 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseEntity.hpp"

#include <iostream>

BaseEntity::BaseEntity()
		: _health(DEFAULT_HEALTH), _position(DEFAULT_POSITION), _skin(""),
			_speed(0) {}

BaseEntity::BaseEntity( int health, Point position,
	std::string skin, int speed )
		: _health(health), _position(position), _skin(skin),
			_speed(speed) {}

BaseEntity::BaseEntity( const BaseEntity &other )
		: _health(other._health), _position(other._position) {}

BaseEntity::~BaseEntity() {}

int BaseEntity::getHealth( void ) const {
	return (this->_health);
}

void BaseEntity::setHealth( const int health ) {
	this->_health = health;
}

Point BaseEntity::getPosition( void ) const {
	return (this->_position);
}

void BaseEntity::setPosition( const Point position ) {
	this->_position = position;
}

std::string BaseEntity::getSkin( void ) const {
	return (this->_skin);
}

void BaseEntity::setSkin( std::string skin ) {
	this->_skin = skin;
}

int BaseEntity::getSpeed( void ) const {
	return (this->_speed);
}

void BaseEntity::setSpeed( const int speed ) {
	this->_speed = speed;
}

BaseEntity &BaseEntity::operator=( const BaseEntity &other ) {
	this->_health = other._health;
	this->_position = other._position;
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const BaseEntity &instance ) {
	stream << "{BaseEntity:"
		<< "health=" << instance.getHealth() << ','
		<< "position=" << instance.getPosition() << '}';
	return (stream);
}
