/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyFries.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:17:53 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 02:02:26 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#ifndef ENEMY_FRIES_HPP
# define ENEMY_FRIES_HPP


# include "AEnemy.hpp"

# define FRIES_SKIN "F"
# define FRIES_SPEED 80
# define FRIES_HEALTH 1
# define FRIES_SHOOT_RATE 10
# define FRIES_SHOOT_SPEED 10

class EnemyFries : public AEnemy {
public:
	EnemyFries();
	EnemyFries( Point position );
	EnemyFries( const EnemyFries &other );
	~EnemyFries();

	void	move( size_t frame );
	void	shoot( size_t frame );

	EnemyFries &operator=( const EnemyFries &other );
};

std::ostream	&operator<<( std::ostream &stream, const EnemyFries &instance );


#endif // ENEMY_FRIES_HPP
