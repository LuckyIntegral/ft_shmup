/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:17:11 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 16:24:24 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef GAME_HPP
# define GAME_HPP


# include <vector>
# include <ncurses.h>
# include <cstddef>
# include <cstdlib>
# include <ctime>
# include <iostream>
# include <ncurses.h>
# include <unistd.h>

# include "entity/player/Player.hpp"
# include "entity/utils/BaseEntity.hpp"
# include "entity/enemy/EnemyBurger.hpp"
# include "entity/enemy/EnemyFries.hpp"
# include "entity/enemy/EnemyHotDog.hpp"
# include "entity/enemy/EnemyLolipop.hpp"
# include "entity/enemy/EnemyPizza.hpp"

# define DEFAULT_GAME_STATUS PLAYING
# define DEFAULT_IS_WON false
# define SCREEN_WIDTH 50
# define STATS_HEIGHT 5
# define BATTLE_HEIGHT 30
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
	std::vector<BaseEntity *>	_bullets;
	GameStatus			_gameStatus;

	Player				_player;
	int					_score;
	WINDOW				*_mainWin;
	WINDOW				*_statsWin;
	WINDOW				*_battleWin;

	// screen atributtes
	int					_screenHeight;
	int					_screenWidth;

	static int			_spawnRate;

public:
	Game();
	~Game();

	// Methods
	void			init( void );
	void			run( void );
	void			pauseGame( void );
	void			drawEnd( void );
	void			destroy( void );
	void			keyPressed( int key );
	void			updateAll( size_t frame );
	void			drawBattle( void );
	void			drawStats( void );
	void			spawnEntity( void );
	void			drawEntity(  BaseEntity *entity  );
	void			addEntity( BaseEntity *entity );

	// Getters and setters
	GameStatus		getGameStatus( void ) const;
	void			setGameStatus( const GameStatus gameStatus );

	WINDOW			*getMainWin( void ) const;
	void			setMainWin( WINDOW *mainWin );

	WINDOW			*getStatsWin( void ) const;
	void			setStatsWin( WINDOW *statsWin );

	WINDOW			*getBattleWin( void ) const;
	void			setBattleWin( WINDOW *battleWin );

	class WrongWindowSizeException : public std::exception {
		virtual const char *what() const throw();
	};
};


#endif // GAME_HPP
