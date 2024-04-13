/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:09:10 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/13 17:17:33 by tkasbari         ###   ########.fr       */
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

void	Player::draw( WINDOW *win ) const {
	mvwprintw(win, this->getPosition().getY(), this->getPosition().getX(), "P");
}

std::ostream	&operator<<( std::ostream &stream, const Player &instance ) {
	stream << "{Player:{"
		<< "health=" << instance.getHealth()
		<< ",position=" << instance.getPosition()
		<< "}}";
	return (stream);
}
