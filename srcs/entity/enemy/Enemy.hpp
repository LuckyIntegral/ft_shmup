/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:52:09 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 19:42:12 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <cstddef>

# include "../utils/BaseEntity.hpp"

class Enemy : public BaseEntity {
private:
	int			_shootRate;
	int			_shootSpeed;
	const int	_scorePoints;

public:
	Enemy();
	Enemy( int health, Point position, std::string skin,
		int speed, int shootRate, int shootSpeed, int scorePoints );
	Enemy( const Enemy &other );
	~Enemy();

	void		move( size_t frame );
	void		shoot( size_t frame );

	int			getShootRate( void ) const;
	void		setShootRate( const int shootRate );
	int			getShootSpeed( void ) const;
	void		setShootSpeed( const int shootSpeed );
	int			getScorePoints( void ) const;

	Enemy	&operator=( const Enemy &other );
};


#endif // ENEMY_HPP
