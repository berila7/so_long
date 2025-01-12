#ifndef SO_LONG_H
# define SO_LONG_H

/* Standard C Libraries we'll need throughout the project */
# include <mlx.h>        // For graphics handling
# include <stdlib.h>     // For memory allocation and exit
# include <unistd.h>     // For read and write
# include <fcntl.h>      // For open
# include <stdio.h>      // For perror
# include "./get_next_line.h"
# include "../lib/libft/libft.h"

// Define game constants 
# define TILE_SIZE 50
# define WIN_TITLE "King's Treasure"

// Define map components
# define EMPTY '0'
# define WALL '1'
# define COLLECT 'C'
# define EXIT 'E'
# define PLAYER 'P'

/* Error messages */
# define ERR_ARGS "Error\nInvalid number of arguments"
# define ERR_FILE "Error\nCould not open file"
# define ERR_MAP "Error\nInvalid map"
# define ERR_MLX "Error\nMLX initialization failed"


typedef struct	s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*player;
	void	*floor;
	void	*wall;
	void	*collectible;
	void	*exit;

	char	**map;

	int		map_h;
	int		map_w;
	int		win_h;
	int		win_w;
	int		collectables;
	int		player_x;
	int		player_y;
	int		fd;
	int		counter;
}	t_game;

int 	map_reading(t_game *game, char *av[]);
void	put_to_window(t_game *game);
void    put_images(t_game *game);
int 	exit_point(t_game *game);
int 	controls_working(int command, t_game *game);

#endif