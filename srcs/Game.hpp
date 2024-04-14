/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:17:11 by vfrants           #+#    #+#             */
/*   Updated: 2024/04/14 23:26:17 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef GAME_HPP
# define GAME_HPP

# define ENEMY_BULLET_SPEED 8
# define ENEMY_BULLET_SKIN "🔻"

# include <vector>
# include <ncurses.h>
# include <cstddef>
# include <cstdlib>
# include <ctime>
# include <iostream>
# include <ncurses.h>
# include <unistd.h>
#include <algorithm>

# include "entity/player/Player.hpp"
# include "entity/utils/BaseEntity.hpp"
# include "entity/enemy/EnemyFactory.hpp"
# include "entity/enemy/Enemy.hpp"

# define DEFAULT_GAME_STATUS PLAYING
# define DEFAULT_IS_WON false
# define SCREEN_WIDTH 50
# define STATS_HEIGHT 6
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
	OVER
}			GameStatus;

class Game {
protected:
	std::vector<Enemy *>	_enemies;
	std::vector<Bullet *>	_bullets;
	GameStatus			_gameStatus;

	Player				_player;
	int					_score;
	WINDOW				*_mainWin;
	WINDOW				*_statsWin;
	WINDOW				*_battleWin;

	// screen atributtes
	int					_screenHeight;
	int					_screenWidth;

	std::vector<std::string>	_background;
	static int					_spawnRate;


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
	void			drawStats( size_t frame);
	void			spawnEntity( void );
	void			drawEntity(  BaseEntity *entity  );
	void			addEnemy( Enemy *entity );
	void			updateMap( size_t frame );

	void 			refreshBullets( int frame );
	void			shootRandom( int frame );
	void			checkBulletVsEnemy( void );
	void			checkBulletVsPlayer( void );
	void			advanceEnemies( size_t frame );

	// Getters and setters
	GameStatus		getGameStatus( void ) const;
	void			setGameStatus( const GameStatus gameStatus );

	WINDOW			*getMainWin( void ) const;
	void			setMainWin( WINDOW *mainWin );

	WINDOW			*getStatsWin( void ) const;
	void			setStatsWin( WINDOW *statsWin );

	WINDOW			*getBattleWin( void ) const;
	void			setBattleWin( WINDOW *battleWin );

	std::vector<Bullet *>	getBullets( void );

	class WrongWindowSizeException : public std::exception {
		virtual const char *what() const throw();
	};
};

#endif // GAME_HPP
