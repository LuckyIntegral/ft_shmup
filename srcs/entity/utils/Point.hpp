/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:55:02 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 01:35:19 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>

# define DEFAULT_Y 0
# define DEFAULT_X 0

class Point {
protected:
	int					_y;
	int					_x;

public:
	Point();
	Point( int y, int x );
	Point( const Point &other );
	~Point();

	int					getY( void ) const;
	void				setY( const int y );
	int					getX( void ) const;
	void				setX( const int x );

	bool				operator==( const Point &other );

	Point &operator=( const Point &other );
};

std::ostream	&operator<<( std::ostream &stream, const Point &instance );


#endif // POINT_HPP
