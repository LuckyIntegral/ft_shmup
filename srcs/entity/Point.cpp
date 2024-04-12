/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:55:02 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/12 21:55:02 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#include <iostream>

Point::Point() : _x(DEFAULT_X), _y(DEFAULT_Y) {}
Point::Point( int x, int y ) : _x(x), _y(y) {}
Point::Point( const Point &other ) : _x(other._x), _y(other._y) {}
Point::~Point() {}

int Point::getX( void ) const {
	return (this->_x);
}

void Point::setX( const int x ) {
	this->_x = x;
}

int Point::getY( void ) const {
	return (this->_y);
}

void Point::setY( const int y ) {
	this->_y = y;
}

Point &Point::operator=( const Point &other ) {
	this->_x = other._x;
	this->_y = other._y;
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const Point &instance ) {
	stream << "{Point:"
		<< "x=" << instance.getX() << ','
		<< "y=" << instance.getY() << '}';
	return (stream);
}
