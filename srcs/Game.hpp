/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfdfdfdfd <fdfdfdfd>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:17:11 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/12 23:18:05 by dfdfdfdfd        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef GAME_HPP
# define GAME_HPP


# include <vector>
# include <ncurses.h>

# include "entity/Player.hpp"
# include "entity/BaseEntity.hpp"

# define DEFAULT_IS_FINISHED false
# define DEFAULT_IS_WON false
# define SCREEN_HEIGHT 800
# define SCREEN_WIDTH 600
# define DEFAULT_PLAYER_HEALTH 3
# define DEFAULT_POSITION_Y (SCREEN_HEIGHT - 20)
# define DEFAULT_POSITION_X (SCREEN_WIDTH / 2)
# define PLAYER_SPEED 5

typedef enum eDirection {
	UP,
	DOWN,
	LEFT,
	RIGHT
}			Direction;

class Game {
protected:
	std::vector<BaseEntity *>	_entities;
	bool				_isFinished;
	bool				_isWon;

	Player				_player;
	int					_score;

	// screen atributtes
	int					_screenHeight;
	int					_screenWidth;

public:
	Game();
	~Game();

	// Methods
	void				run( void );
	void				init( void );
	void				keyPressed( int key );
	void				printEntities( void ) const;
	void				addEntity( BaseEntity *entity );

	// Getters and setters
	bool				getIsfinished( void ) const;
	void				setIsfinished( const bool isFinished );
	bool				getIswon( void ) const;
	void				setIswon( const bool isWon );

};


#endif // GAME_HPP
