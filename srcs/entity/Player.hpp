/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:09:10 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/13 22:54:14 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PLAYER_HPP
# define PLAYER_HPP


# include <vector>

# include "Bullet.hpp"
# include "BaseEntity.hpp"

# define PLAYER_BULLET_SPEED 4

class Player : public BaseEntity {
protected:
	std::vector<Bullet *>	_bullets;

public:
	Player();
	Player( int health, Point position );
	~Player();

	void	move( size_t frame );

	void	shoot( void );
	void 	refreshBullets( int frame );

	void	goUp( int steps );
	void	goDown( int steps );
	void	goLeft( int steps );
	void	goRight( int steps );

	std::vector<Bullet *>	getBullets( void );
};

std::ostream	&operator<<( std::ostream &stream, const Player &instance );


#endif // PLAYER_HPP
