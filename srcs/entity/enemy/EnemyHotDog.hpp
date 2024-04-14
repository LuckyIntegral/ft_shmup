/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyHotDog.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:17:53 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 12:20:19 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#ifndef ENEMY_HOT_DOG_HPP
# define ENEMY_HOT_DOG_HPP


# include "AEnemy.hpp"

# define HOT_DOG_SKIN "🌭"
# define HOT_DOG_SPEED 120
# define HOT_DOG_HEALTH 1
# define HOT_DOG_SHOOT_RATE 10
# define HOT_DOG_SHOOT_SPEED 10

class EnemyHotDog : public AEnemy {
public:
	EnemyHotDog();
	EnemyHotDog( Point position );
	EnemyHotDog( const EnemyHotDog &other );
	~EnemyHotDog();

	void	move( size_t frame );
	void	shoot( size_t frame );

	EnemyHotDog &operator=( const EnemyHotDog &other );
};

std::ostream	&operator<<( std::ostream &stream, const EnemyHotDog &instance );


#endif // ENEMY_HOT_DOG_HPP
