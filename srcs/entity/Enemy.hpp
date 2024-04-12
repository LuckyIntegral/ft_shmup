/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfdfdfdfd <fdfdfdfd>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:08:25 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/12 22:10:18 by dfdfdfdfd        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ENEMY_HPP
# define ENEMY_HPP


# include <string>
# include "BaseEntity.hpp"

# define DEFAULT_SPEED 10

class Enemy : public BaseEntity {
protected:
	int					_speed;

public:
	Enemy();
	Enemy( int speed, int health, Point position );
	Enemy( const Enemy &other );
	~Enemy();

	int					getSpeed( void ) const;
	void				setSpeed( const int speed );

	Enemy &operator=( const Enemy &other );
};

std::ostream	&operator<<( std::ostream &stream, const Enemy &instance );


#endif // ENEMY_HPP
