/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfdfdfdfd <fdfdfdfd>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:09:10 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/12 23:16:32 by dfdfdfdfd        ###   ########.fr       */
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
};

std::ostream	&operator<<( std::ostream &stream, const Player &instance );


#endif // PLAYER_HPP
