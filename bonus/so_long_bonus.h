/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:11:52 by mberila           #+#    #+#             */
/*   Updated: 2025/01/25 20:26:34 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

// Define game constants 
# define TILE_SIZE 50
# define WIN_TITLE "King's Treasure"

// Define map components
# define EMPTY '0'
# define WALL '1'
# define COLLECT 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define ENEMY 'X'

# define ANIMATION_FRAMES 5
# define ANIMATION_SPEED 10
# define ENEMY_SPEED 30

# define P_RIGHT 0
# define P_LEFT  1
# define P_UP    2
# define P_DOWN  3

// Define keys
# define KEYUP 13
# define KEYDOWN 1
# define KEYLEFT 0
# define KEYRIGHT 2
# define ESCKEY 53
# define ON_DESTROY 17
# define NO_EVENT_MASK 0

/* Error messages */
# define ERR_MAP_EX "Error\nMap file must be .ber\n"
# define ERR_MAP_ARG "Error\nUsage: ./so_long <map.ber>\n"
# define ERR_MAP_OPEN "Error\nCannot open map file\n"
# define ERR_MAP_EMPTY "Error\nMap is empty\n"
# define ERR_MAP_IN "Error\nMap is invalid\n"
# define MALLOC_FAIL "Error\nMemory allocation failed\n"
# define ERR_RECT "Error\nMap is not rectangular\n"
# define ERR_WALLS "Error\nMap must be surrounded by walls\n"
# define ERR_PLAYER "Error\nMap must have exactly one player\n"
# define ERR_EXIT "Error\nMap must have exactly one exit\n"
# define ERR_COLLECT "Error\nMap must have at least one collectible\n"
# define ERR_CHARS "Error\nMap contains invalid characters\n"
# define ERR_PATH "Error\nNo valid path\n"
# define ERR_MLX "Error\nMLX initialization failed\n"
# define ERR_DIMEN "Error\nMap dimensions not set\n"
# define LOAD_FAIL "Error\nFailed to load texture: %s\n"
# define ENE_CAUGHT "\nGame Over! Enemy caught you!\n"

/* Colors*/
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*player_img;
	void	*collect_img;
	void	*exit_img;
	void	*floor;
	void	*enemy_img;

	char    **map;

	void	*collect_frames[ANIMATION_FRAMES];
	void	*player_frames[4];
	int		player_direction;
	int		collect_current_frame;
	int		collect_count;

    int     height;
    int		width;
    int     collect;
    int     exit;
    int     player; 
	int		moves;
	int		enemy_dir;
	int		enemy_y;
	int		enemy_x;
	int		enemy_timer;
	int		exit_pos_x;
	int		exit_pos_y;
	int     animation_timer;
}	t_game;

t_game	*init_game(void);
int		read_map(t_game *game, char *file);
void	free_game(t_game *game);
void	print_error(char *message);
int     validate_map(t_game *game);
void	free_map(char **map, int height);
int		check_path(t_game *game);
int		init_game_window(t_game *game);
int		init_mlx(t_game *game);
int		init_textures(t_game *game);
int		render_map(t_game *game);
void	find_char_pos(t_game *game, int *x, int *y, char c);
int		close_window(t_game *game);
void	move_player(t_game *game, int keycode);
void	*load_texture(t_game *game, char *path);
void	update_animations(t_game *game);
void	init_animations(t_game *game);
void	update_enemy(t_game *game);

#endif