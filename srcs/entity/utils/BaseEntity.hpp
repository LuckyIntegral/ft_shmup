/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseEntity.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:07:11 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 20:23:15 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BASE_ENTITY_HPP
# define BASE_ENTITY_HPP


# include <cstddef>
# include <ncurses.h>

# include "Point.hpp"

# define DEFAULT_HEALTH 1
# define DEFAULT_POSITION Point(DEFAULT_X, DEFAULT_Y)

class BaseEntity {
protected:
	int					_health;
	Point				_position;
	std::string			_skin;
	int					_speed;

public:
	BaseEntity();
	BaseEntity( int health, Point position, std::string skin, int speed );
	BaseEntity( const BaseEntity &other );
	virtual ~BaseEntity();

	virtual void		move( size_t frame ) = 0;

	int					getHealth( void ) const;
	void				setHealth( const int health );
	Point				getPosition( void ) const;
	void				setPosition( const Point position );
	std::string			getSkin( void ) const;
	void				setSkin( std::string skin );
	int					getSpeed( void ) const;
	void				setSpeed( const int speed );

	BaseEntity &operator=( const BaseEntity &other );
};

std::ostream	&operator<<( std::ostream &stream, const BaseEntity &instance );


#endif // BASE_ENTITY_HPP
