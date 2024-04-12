/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfdfdfdfd <fdfdfdfd>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:09:10 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/12 23:17:18 by dfdfdfdfd        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

#include <iostream>

Player::Player() {}
Player::Player( int health, Point position ) : BaseEntity(health, position) {}
Player::~Player() {}

void	Player::goUp( int steps ) {
	this->setPosition(Point(this->getPosition().getX(), this->getPosition().getY() - steps));
}

void	Player::goDown( int steps ) {
	this->setPosition(Point(this->getPosition().getX(), this->getPosition().getY() + steps));
}

void	Player::goLeft( int steps ) {
	this->setPosition(Point(this->getPosition().getX() - steps, this->getPosition().getY()));
}

void	Player::goRight( int steps ) {
	this->setPosition(Point(this->getPosition().getX() + steps, this->getPosition().getY()));
}


std::ostream	&operator<<( std::ostream &stream, const Player &instance ) {
	stream << "{Player:{"
		<< "health=" << instance.getHealth()
		<< ",position=" << instance.getPosition()
		<< "}}";
	return (stream);
}
