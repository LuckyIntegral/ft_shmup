/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:07:40 by tkasbari          #+#    #+#             */
/*   Updated: 2024/04/14 15:57:56 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"
#include "BaseEntity.hpp"

#include <iostream>

Bullet::Bullet() : BaseEntity(DEFAULT_BULLET_HEALTH, Point(0, 0), DEFAULT_BULLET_SKIN, DEFAULT_BULLET_SPEED), _type(t_bulletType::ENEMY) {}

Bullet::Bullet( Point position, t_bulletType owner, int speed ) : BaseEntity(DEFAULT_BULLET_HEALTH, position, DEFAULT_BULLET_SKIN, speed), _type(owner) {}

Bullet::Bullet( Point position, t_bulletType owner, std::string skin, int speed ) : BaseEntity(DEFAULT_BULLET_HEALTH, position, skin, speed), _type(owner) {}

Bullet::~Bullet() {}

void	Bullet::move( size_t frame ) {
	int	bulletDirection;
	if (frame % this->getSpeed() == 0) {
		if (this->_type == t_bulletType::ENEMY)
			bulletDirection = 1;
		else
			bulletDirection = -1;
		this->setPosition(Point(this->getPosition().getY() + bulletDirection,
			this->getPosition().getX()));
	}
}

std::ostream	&operator<<( std::ostream &stream, const Bullet & ) {
	stream << "{Bullet:{}}";
	return (stream);
}
