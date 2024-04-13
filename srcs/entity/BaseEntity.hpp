/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseEntity.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:07:11 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/13 16:42:14 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BASE_ENTITY_HPP
# define BASE_ENTITY_HPP


# include "Point.hpp"
# include <ncurses.h>

# define DEFAULT_HEALTH 1
# define DEFAULT_POSITION Point(DEFAULT_X, DEFAULT_Y)

class BaseEntity {
protected:
	int					_health;
	Point				_position;

public:
	BaseEntity();
	BaseEntity( int health, Point position );
	BaseEntity( const BaseEntity &other );
	virtual ~BaseEntity();

	void				draw(WINDOW *win) const;

	int					getHealth( void ) const;
	void				setHealth( const int health );
	Point				getPosition( void ) const;
	void				setPosition( const Point position );

	BaseEntity &operator=( const BaseEntity &other );
};

std::ostream	&operator<<( std::ostream &stream, const BaseEntity &instance );


#endif // BASE_ENTITY_HPP
