/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEnemy.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:52:09 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 01:56:51 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef A_ENEMY_HPP
# define A_ENEMY_HPP


#include <cstddef>

# include "../utils/BaseEntity.hpp"

class AEnemy : public BaseEntity {
public:
	AEnemy();
	AEnemy( int health, Point position, std::string skin, int speed );
	AEnemy( const AEnemy &other );
	virtual ~AEnemy();

	virtual void		shoot( size_t frame ) = 0;
	
};


#endif // A_ENEMY_HPP
