/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfdfdfdfd <fdfdfdfd>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:09:41 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/12 21:14:10 by dfdfdfdfd        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.hpp"

#include <iostream>

Entity::Entity() : _health(DEFAULT_HEALTH), _speed(DEFAULT_SPEED), _name(DEFAULT_NAME) {}
Entity::Entity( int health, int speed, std::string name ) : _health(health), _speed(speed), _name(name) {}
Entity::Entity( const Entity &other ) : _health(other._health), _speed(other._speed), _name(other._name) {}
Entity::~Entity() {}

int Entity::getHealth( void ) const {
	return (this->_health);
}

void Entity::setHealth( const int health ) {
	this->_health = health;
}

int Entity::getSpeed( void ) const {
	return (this->_speed);
}

void Entity::setSpeed( const int speed ) {
	this->_speed = speed;
}

std::string Entity::getName( void ) const {
	return (this->_name);
}

void Entity::setName( const std::string name ) {
	this->_name = name;
}

Entity &Entity::operator=( const Entity &other ) {
	this->_health = other._health;
	this->_speed = other._speed;
	this->_name = other._name;
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const Entity &instance ) {
	stream << "{Entity:"
		<< "health=" << instance.getHealth() << ','
		<< "speed=" << instance.getSpeed() << ','
		<< "name=" << instance.getName() << '}';
	return (stream);
}
