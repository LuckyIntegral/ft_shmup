/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyBurger.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:08:25 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/13 18:59:08 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ENEMY_BURGER_HPP
# define ENEMY_BURGER_HPP


# include "AEnemy.hpp"

# define BURGER_SKIN "🍔"
# define BURGER_SPEED 100
# define BURGER_HEALTH 1
# define BURGER_BULLET_RATE 100
# define BURGER_BULLET_SPEED 200


class EnemyBurger : public AEnemy {
public:
	EnemyBurger();
	EnemyBurger( Point position );
	EnemyBurger( const EnemyBurger &other );
	~EnemyBurger();

	void	move( size_t frame );
	void	shoot( size_t frame );

	EnemyBurger &operator=( const EnemyBurger &other );
};

std::ostream	&operator<<( std::ostream &stream, const EnemyBurger &instance );


#endif // ENEMY_BURGER_HPP
