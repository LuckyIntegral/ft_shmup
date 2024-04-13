/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:55:02 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/13 22:21:26 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#include <iostream>

Point::Point() : _y(DEFAULT_Y), _x(DEFAULT_X) {}
Point::Point( int y, int x ) : _y(y), _x(x) {}
Point::Point( const Point &other ) : _y(other._y), _x(other._x) {}
Point::~Point() {}

void Point::setX( const int x ) {
	this->_x = x;
}

int Point::getX( void ) const {
	return (this->_x);
}

void Point::setY( const int y ) {
	this->_y = y;
}

int Point::getY( void ) const {
	return (this->_y);
}

bool	Point::operator==( const Point &other ) {
	return (this->_y == other._y && this->_x == other._x);
}

Point &Point::operator=( const Point &other ) {
	this->_y = other._y;
	this->_x = other._x;
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const Point &instance ) {
	stream << "{Point:"
		<< "y=" << instance.getY() << ','
		<< "x=" << instance.getX() << '}';
	return (stream);
}
