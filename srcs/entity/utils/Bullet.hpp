/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:07:40 by tkasbari          #+#    #+#             */
/*   Updated: 2024/04/13 22:53:29 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BULLET_HPP
# define BULLET_HPP

# define DEFAULT_BULLET_SKIN "|"
# define DEFAULT_BULLET_SPEED 1
# define DEFAULT_BULLET_HEALTH 1

# include "BaseEntity.hpp"
# include "Point.hpp"

typedef enum e_bulletType {
	PLAYER,
	ENEMY
}	t_bulletType;

class Bullet : public BaseEntity {
protected:
	t_bulletType	_type;

public:
	Bullet();
	Bullet( Point position, t_bulletType owner, int speed );
	~Bullet();

	void move( size_t frame );
};

std::ostream	&operator<<( std::ostream &stream, const Bullet &instance );


#endif // BULLET_HPP
