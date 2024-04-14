/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyPizza.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:17:53 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 01:24:18 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#ifndef ENEMY_PIZZA_HPP
# define ENEMY_PIZZA_HPP


# include "AEnemy.hpp"

# define PIZZA_SKIN "🍕"
# define PIZZA_SPEED 180
# define PIZZA_HEALTH 1
# define PIZZA_SHOOT_RATE 10
# define PIZZA_SHOOT_SPEED 10

class EnemyPizza : public AEnemy {
public:
	EnemyPizza();
	EnemyPizza( Point position );
	EnemyPizza( const EnemyPizza &other );
	~EnemyPizza();

	void	move( size_t frame );
	void	shoot( size_t frame );

	EnemyPizza &operator=( const EnemyPizza &other );
};

std::ostream	&operator<<( std::ostream &stream, const EnemyPizza &instance );


#endif // ENEMY_PIZZA_HPP
