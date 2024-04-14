/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyLolipop.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:17:53 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 02:03:34 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#ifndef ENEMY_LOLI_POP_HPP
# define ENEMY_LOLI_POP_HPP


# include "AEnemy.hpp"

# define LOLI_POP_SKIN "L"
# define LOLI_POP_SPEED 50
# define LOLI_POP_HEALTH 1
# define LOLI_POP_BULLET_RATE 15
# define LOLI_POP_BULLET_SPEED 30

class EnemyLolipop : public AEnemy {
public:
	EnemyLolipop();
	EnemyLolipop( Point position );
	EnemyLolipop( const EnemyLolipop &other );
	~EnemyLolipop();

	void	move( size_t frame );
	void	shoot( size_t frame );

	EnemyLolipop &operator=( const EnemyLolipop &other );
};

std::ostream	&operator<<( std::ostream &stream, const EnemyLolipop &instance );


#endif // ENEMY_LOLI_POP_HPP
