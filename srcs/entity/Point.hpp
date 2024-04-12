/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfdfdfdfd <fdfdfdfd>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:55:02 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/12 21:55:09 by dfdfdfdfd        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef POINT_HPP
# define POINT_HPP


# include <string>

# define DEFAULT_X 0
# define DEFAULT_Y 0

class Point {
protected:
	int					_x;
	int					_y;

public:
	Point();
	Point( int x, int y );
	Point( const Point &other );
	~Point();

	int					getX( void ) const;
	void				setX( const int x );
	int					getY( void ) const;
	void				setY( const int y );

	Point &operator=( const Point &other );
};

std::ostream	&operator<<( std::ostream &stream, const Point &instance );


#endif // POINT_HPP
