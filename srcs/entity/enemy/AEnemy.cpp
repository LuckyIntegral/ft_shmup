/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEnemy.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:52:09 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 02:08:24 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEnemy.hpp"


AEnemy::AEnemy() : BaseEntity() {}
AEnemy::AEnemy( int health, Point position, std::string skin, int speed ) : BaseEntity(health, position, skin, speed) {}
AEnemy::AEnemy( const AEnemy &instance ) : BaseEntity(instance) {}
AEnemy::~AEnemy() {}
