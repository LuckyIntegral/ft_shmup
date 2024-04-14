/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyFactory.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:20:30 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 19:45:14 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnemyFactory.hpp"

EnemyFactory::EnemyFactory() {}
EnemyFactory::~EnemyFactory() {}

Enemy	*EnemyFactory::createEnemy(EnemyType type, Point position) {
	if (type == BURGER) {
		return new Enemy(BURGER_HEALTH, position, BURGER_SKIN, BURGER_SPEED, BURGER_SHOOT_RATE, BURGER_SHOOT_SPEED, BURGER_SCORE_POINTS);
	} else if (type == FRIES) {
		return new Enemy(FRIES_HEALTH, position, FRIES_SKIN, FRIES_SPEED, FRIES_SHOOT_RATE, FRIES_SHOOT_SPEED, FRIES_SCORE_POINTS);
	} else if (type == HOT_DOG) {
		return new Enemy(HOT_DOG_HEALTH, position, HOT_DOG_SKIN, HOT_DOG_SPEED, HOT_DOG_SHOOT_RATE, HOT_DOG_SHOOT_SPEED, HOT_DOG_SCORE_POINTS);
	} else if (type == ICE_CREAM) {
		return new Enemy(ICE_CREAM_HEALTH, position, ICE_CREAM_SKIN, ICE_CREAM_SPEED, ICE_CREAM_SHOOT_RATE, ICE_CREAM_SHOOT_SPEED, ICE_CREAM_SCORE_POINTS);
	} else if (type == PIZZA) {
		return new Enemy(PIZZA_HEALTH, position, PIZZA_SKIN, PIZZA_SPEED, PIZZA_SHOOT_RATE, PIZZA_SHOOT_SPEED, PIZZA_SCORE_POINTS);
	} else {
		return new Enemy(LOLIPOP_HEALTH, position, LOLIPOP_SKIN, LOLIPOP_SPEED, LOLIPOP_SHOOT_RATE, LOLIPOP_SHOOT_SPEED, LOLIPOP_SCORE_POINTS);
	}
}
