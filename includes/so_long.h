#ifndef SO_LONG_H
# define SO_LONG_H

/* Standard C Libraries we'll need throughout the project */
# include <mlx.h>        // For graphics handling
# include <stdlib.h>     // For memory allocation and exit
# include <unistd.h>     // For read and write
# include <fcntl.h>      // For open
# include <stdio.h>      // For perror
# include "./get_next_line.h"

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
	void	*mlx_ptr;
	void	*mlx_win;
	char	**map;
	size_t	map_h;
	size_t	map_w;
	size_t	win_h;
	size_t	win_w;
	int		player_x;
	int		player_y;
	int		player_frame;
	int		fd;
}	t_game;

void draw_map(void *mlx, void *mlx_win);
int map_height();
int map_width();
#endif