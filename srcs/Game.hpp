/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:17:11 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/13 17:35:06 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef GAME_HPP
# define GAME_HPP


# include <vector>
# include <ncurses.h>

# include "entity/Player.hpp"
# include "entity/BaseEntity.hpp"

# define DEFAULT_GAME_STATUS PLAYING
# define DEFAULT_IS_WON false
# define SCREEN_WIDTH 20
# define STATS_HEIGHT 5
# define BATTLE_HEIGHT 15
# define DEFAULT_PLAYER_HEALTH 3
# define DEFAULT_POSITION_Y (BATTLE_HEIGHT - 1)
# define DEFAULT_POSITION_X (SCREEN_WIDTH / 2)
# define PLAYER_SPEED 1

typedef enum eDirection {
	UP,
	DOWN,
	LEFT,
	RIGHT
}			Direction;

typedef enum eGameStatus {
	PLAYING,
	PAUSED,
	ABORTED,
	LOST,
	WON
}			GameStatus;

class Game {
protected:
	std::vector<BaseEntity *>	_entities;
	GameStatus			_gameStatus;

	Player				_player;
	int					_score;
	WINDOW				*_mainWin;
	WINDOW				*_statsWin;
	WINDOW				*_battleWin;

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
	void				updateAll( void );
	void				drawBattle( void ) const;
	void				drawStats( void ) const;
	void				printEntities( void ) const;
	void				addEntity( BaseEntity *entity );

	// Getters and setters
	GameStatus		getGameStatus( void ) const;
	void			setGameStatus( const GameStatus gameStatus );

	WINDOW			*getMainWin( void ) const;
	void			setMainWin( WINDOW *mainWin );

	WINDOW			*getStatsWin( void ) const;
	void			setStatsWin( WINDOW *statsWin );

	WINDOW			*getBattleWin( void ) const;
	void			setBattleWin( WINDOW *battleWin );

};


#endif // GAME_HPP
