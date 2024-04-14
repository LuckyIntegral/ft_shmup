/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyIceCream.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:17:53 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 12:20:36 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#ifndef ENEMY_ICE_CREAM_HPP
# define ENEMY_ICE_CREAM_HPP


# include "AEnemy.hpp"

# define ICE_CREAM_SKIN "🍦"
# define ICE_CREAM_SPEED 200
# define ICE_CREAM_HEALTH 1
# define ICE_CREAM_SHOOT_RATE 10
# define ICE_CREAM_SHOOT_SPEED 10

class EnemyIceCream : public AEnemy {
public:
	EnemyIceCream();
	EnemyIceCream( Point position );
	EnemyIceCream( const EnemyIceCream &other );
	~EnemyIceCream();

	void	move( size_t frame );
	void	shoot( size_t frame );

	EnemyIceCream &operator=( const EnemyIceCream &other );
};

std::ostream	&operator<<( std::ostream &stream, const EnemyIceCream &instance );


#endif // ENEMY_ICE_CREAM_HPP
