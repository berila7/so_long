/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:11:52 by mberila           #+#    #+#             */
/*   Updated: 2025/01/18 18:48:55 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>        // For graphics handling
# include <stdlib.h>     // For memory allocation and exit
# include <unistd.h>     // For read and write
# include <fcntl.h>      // For open
# include <stdio.h>      // For perror
# include "./get_next_line.h"
# include "../../lib/libft/libft.h"

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

/* Colors*/
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_game
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
	int		collectibles;
	int		player_x;
	int		player_y;
	int		fd;
	int		counter;
	int		player_count;
	int		exit_count;
}	t_game;

// Flood fill structure to track visited positions
typedef struct s_fill {
    char **visited;
    int collectibles_reached;
    int exit_reached;
}	t_fill;

int 	map_reading(t_game *game, char *av[]);
void	put_to_window(t_game *game);
void    put_images(t_game *game);
int 	exit_point(t_game *game);
int 	controls_working(int command, t_game *game);
t_pos	*get_char_pos(t_game *game, char c);
int		check_errors(t_game *game);
void 	cleanup(t_game *game);

#endif