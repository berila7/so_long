/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:17:03 by mberila           #+#    #+#             */
/*   Updated: 2025/01/12 11:30:14 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void    put_player(t_game *game)
{
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->player, game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
}

void    put_collectable(t_game *game, int y, int x)
{
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->collectible, x * TILE_SIZE, y * TILE_SIZE);
    game->collectables++;
}

void    put_images(t_game *game)
{
	int	tailSize;
	
	tailSize = TILE_SIZE;
	game->floor = mlx_xpm_file_to_image(game->mlx, "./assets/images/floor.xpm", &tailSize, &tailSize);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./assets/images/wall.xpm", &tailSize, &tailSize);
	game->player = mlx_xpm_file_to_image(game->mlx, "./assets/images/player.xpm", &tailSize, &tailSize);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./assets/images/exit.xpm", &tailSize, &tailSize);
	game->collectible = mlx_xpm_file_to_image(game->mlx, "./assets/images/collectible.xpm", &tailSize, &tailSize);
}

void	put_to_window(t_game *game)
{
	int	y;
	int	x;

	game->collectables = 0;
	y = 0;
	while (y < game->map_h)
	{
		x = 0;
		while (game->map[y][x])
		{
			if(game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, x * TILE_SIZE, y * TILE_SIZE);
			else if(game->map[y][x] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor, x * TILE_SIZE, y * TILE_SIZE);
				put_collectable(game, y, x);
			}
			else if (game->map[y][x] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit, x * TILE_SIZE, y * TILE_SIZE);
			}
			else
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	// mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor, x * TILE_SIZE, y * TILE_SIZE);
	put_player(game);
}