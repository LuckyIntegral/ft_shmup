/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyFactory.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:20:30 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 20:03:05 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ENEMY_FACTORY_HPP
# define ENEMY_FACTORY_HPP

# include "Enemy.hpp"

# define BURGER_SKIN "🍔"
# define BURGER_SPEED 100
# define BURGER_HEALTH 1
# define BURGER_SCORE_POINTS BURGER_HEALTH * 10
# define BURGER_SHOOT_RATE 100
# define BURGER_SHOOT_SPEED 200

# define FRIES_SKIN "🍟"
# define FRIES_SPEED 80
# define FRIES_HEALTH 1
# define FRIES_SCORE_POINTS FRIES_HEALTH * 10
# define FRIES_SHOOT_RATE 10
# define FRIES_SHOOT_SPEED 10

# define HOT_DOG_SKIN "🌭"
# define HOT_DOG_SPEED 120
# define HOT_DOG_HEALTH 1
# define HOT_DOG_SCORE_POINTS HOT_DOG_HEALTH * 10
# define HOT_DOG_SHOOT_RATE 10
# define HOT_DOG_SHOOT_SPEED 10

# define ICE_CREAM_SKIN "🍦"
# define ICE_CREAM_SPEED 200
# define ICE_CREAM_HEALTH 1
# define ICE_CREAM_SCORE_POINTS ICE_CREAM_HEALTH * 10
# define ICE_CREAM_SHOOT_RATE 10
# define ICE_CREAM_SHOOT_SPEED 10

# define LOLIPOP_SKIN "🍭"
# define LOLIPOP_SPEED 50
# define LOLIPOP_HEALTH 1
# define LOLIPOP_SCORE_POINTS LOLIPOP_HEALTH * 10
# define LOLIPOP_SHOOT_RATE 15
# define LOLIPOP_SHOOT_SPEED 30

# define PIZZA_SKIN "🍕"
# define PIZZA_SPEED 180
# define PIZZA_HEALTH 1
# define PIZZA_SCORE_POINTS PIZZA_HEALTH * 10
# define PIZZA_SHOOT_RATE 10
# define PIZZA_SHOOT_SPEED 10

typedef enum EnemyType {
	BURGER,
	FRIES,
	HOT_DOG,
	ICE_CREAM,
	LOLI_POP,
	PIZZA
}	EnemyType;

class EnemyFactory {
private:
	EnemyFactory();
	~EnemyFactory();

public:
	static Enemy	*createEnemy( EnemyType type, Point position );

};


#endif // ENEMY_FACTORY_HPP
