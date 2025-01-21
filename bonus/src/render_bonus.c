/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:17:03 by mberila           #+#    #+#             */
/*   Updated: 2025/01/21 15:17:59 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	put_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->player,
		game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
}

void	put_collectible(t_game *game, int y, int x)
{
	void *coin_image;

	if (game->coin_frame == 0)
		coin_image = game->c_1;
	else if (game->coin_frame == 1)
		coin_image = game->c_2;
	else if (game->coin_frame == 2)
		coin_image = game->c_3;
	else if (game->coin_frame == 3)
		coin_image = game->c_4;
	else
		coin_image = game->c_5;
    mlx_put_image_to_window(game->mlx, game->mlx_win, coin_image,
        x * TILE_SIZE, y * TILE_SIZE);
    game->collectibles++;
}

void	put_enemy(t_game *game, int y, int x)
{
	void *enemy_image;

	if (game->coin_frame == 0)
		enemy_image = game->e_1;
	else if (game->coin_frame == 1)
		enemy_image = game->e_2;
	else if (game->coin_frame == 2)
		enemy_image = game->e_3;
	else if (game->coin_frame == 3)
		enemy_image = game->e_4;
	else
		enemy_image = game->e_5;
    mlx_put_image_to_window(game->mlx, game->mlx_win, enemy_image,
        x * TILE_SIZE, y * TILE_SIZE);
}

void	put_images(t_game *game)
{
	int	tail_size;

	tail_size = TILE_SIZE;
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/floor.xpm", &tail_size, &tail_size);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/wall.xpm", &tail_size, &tail_size);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/player/player.xpm", &tail_size, &tail_size);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/exit.xpm", &tail_size, &tail_size);
	game->collectible = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/collectible.xpm",
			&tail_size, &tail_size);
	game->pl_up = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/player/pl_up.xpm", &tail_size, &tail_size);
	game->pl_r = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/player/pl_r.xpm", &tail_size, &tail_size);
	game->pl_l = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/player/pl_l.xpm", &tail_size, &tail_size);
	game->pl_dw = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/player/pl_dw.xpm", &tail_size, &tail_size);
	game->c_1 = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/collectable/c_1.xpm", &tail_size, &tail_size);
	game->c_2 = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/collectable/c_2.xpm", &tail_size, &tail_size);
	game->c_3 = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/collectable/c_3.xpm", &tail_size, &tail_size);
	game->c_4 = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/collectable/c_4.xpm", &tail_size, &tail_size);
	game->c_5 = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/collectable/c_5.xpm", &tail_size, &tail_size);
	game->e_1 = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/enemy/e_1.xpm", &tail_size, &tail_size);
	game->e_2 = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/enemy/e_2.xpm", &tail_size, &tail_size);
	game->e_3 = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/enemy/e_3.xpm", &tail_size, &tail_size);
	game->e_4 = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/enemy/e_4.xpm", &tail_size, &tail_size);
	game->e_5 = mlx_xpm_file_to_image(game->mlx,
			"./bonus/textures/enemy/e_5.xpm", &tail_size, &tail_size);
}

static void	render_map_tiles(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->wall, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->floor, x * TILE_SIZE, y * TILE_SIZE);
		put_collectible(game, y, x);
	}
	else if (game->map[y][x] == 'X')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->floor, x * TILE_SIZE, y * TILE_SIZE);
		put_enemy(game, y, x);
	}
	else if (game->map[y][x] == 'E')
	{
		if (game->exit)
		{
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->exit, x * TILE_SIZE, y * TILE_SIZE);
		}
		else
			printf(RED"Error: The exit image dosen't exist"RESET);
	}
	else
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->floor, x * TILE_SIZE, y * TILE_SIZE);
}

void	put_to_window(t_game *game)
{
	int	y;
	int	x;

	if (!game || !game->mlx
		|| !game->mlx_win || !game->map
		|| !game->wall || !game->floor
		|| !game->exit || !game->collectible)
	{
		ft_putstr_fd(RED"Error: Null or invalid pointer.\n" RESET, 2);
		exit_point(game);
	}
	game->collectibles = 0;
	y = 0;
	while (y < game->map_h)
	{
		x = 0;
		while (game->map[y][x])
		{
			render_map_tiles(game, y, x);
			x++;
		}
		y++;
	}
	put_player (game);
	animate(game);
	draw_steps(game);
}
