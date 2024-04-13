/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:09:10 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/13 17:16:52 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PLAYER_HPP
# define PLAYER_HPP


# include "BaseEntity.hpp"

class Player : public BaseEntity {
public:
	Player();
	Player( int health, Point position );
	~Player();

	void	goUp( int steps );
	void	goDown( int steps );
	void	goLeft( int steps );
	void	goRight( int steps );
	void	draw( WINDOW *win ) const;
};

std::ostream	&operator<<( std::ostream &stream, const Player &instance );


#endif // PLAYER_HPP
