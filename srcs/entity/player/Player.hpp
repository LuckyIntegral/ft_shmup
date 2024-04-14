/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:09:10 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 20:40:23 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PLAYER_HPP
# define PLAYER_HPP


# include <vector>

# include "../utils/Bullet.hpp"
# include "../utils/BaseEntity.hpp"

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
