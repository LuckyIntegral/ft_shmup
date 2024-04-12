/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfdfdfdfd <fdfdfdfd>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:09:41 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/12 21:13:28 by dfdfdfdfd        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ENTITY_HPP
# define ENTITY_HPP


# include <string>

# define DEFAULT_HEALTH 10
# define DEFAULT_SPEED 20
# define DEFAULT_NAME "hello"

class Entity {
protected:
	int					_health;
	int					_speed;
	std::string			_name;

public:
	Entity();
	Entity( int health, int speed, std::string name );
	Entity( const Entity &other );
	~Entity();

	int					getHealth( void ) const;
	void				setHealth( const int health );
	int					getSpeed( void ) const;
	void				setSpeed( const int speed );
	std::string			getName( void ) const;
	void				setName( const std::string name );

	Entity &operator=( const Entity &other );
};

std::ostream	&operator<<( std::ostream &stream, const Entity &instance );


#endif // ENTITY_HPP
