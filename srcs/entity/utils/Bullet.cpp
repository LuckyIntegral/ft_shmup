/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:07:40 by tkasbari          #+#    #+#             */
/*   Updated: 2024/04/14 20:21:52 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"
#include "BaseEntity.hpp"

#include <iostream>

Bullet::Bullet()
		: BaseEntity(DEFAULT_BULLET_HEALTH, Point(0, 0), DEFAULT_BULLET_SKIN, DEFAULT_BULLET_SPEED),
			_type(t_bulletType::ENEMY) {}

Bullet::Bullet( Point position, t_bulletType owner, int speed )
		: BaseEntity(DEFAULT_BULLET_HEALTH, position, DEFAULT_BULLET_SKIN, speed),
			_type(owner) {}

Bullet::Bullet( Point position, t_bulletType owner, std::string skin, int speed ) : BaseEntity(DEFAULT_BULLET_HEALTH, position, skin, speed), _type(owner) {}

Bullet::~Bullet() {}

void	Bullet::move( size_t frame ) {
	if (frame % this->getSpeed() == 0) {
		if (this->_type == t_bulletType::ENEMY)
			this->setPosition(Point(this->getPosition().getY() + 1,
				this->getPosition().getX()));
		else
			this->setPosition(Point(this->getPosition().getY() - 1,
				this->getPosition().getX()));
	}
}

std::ostream	&operator<<( std::ostream &stream, const Bullet & ) {
	stream << "{Bullet:{}}";
	return (stream);
}
