/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseEntity.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:07:11 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/13 16:43:01 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseEntity.hpp"

#include <iostream>

BaseEntity::BaseEntity() : _health(DEFAULT_HEALTH), _position(DEFAULT_POSITION) {}
BaseEntity::BaseEntity( int health, Point position ) : _health(health), _position(position) {}
BaseEntity::BaseEntity( const BaseEntity &other ) : _health(other._health), _position(other._position) {}
BaseEntity::~BaseEntity() {}

void BaseEntity::draw( WINDOW *win ) const {
	mvwprintw(win, this->_position.getY(), this->_position.getX(), "X");
}

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
