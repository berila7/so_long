/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:17:03 by mberila           #+#    #+#             */
/*   Updated: 2025/01/11 12:13:06 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void    put_player(t_game *game, int x, int y)
{
    mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->player, y * TILE_SIZE, x * TILE_SIZE);
    game->player_x = x;
    game->player_y = y;
}

void    put_collectable(t_game *game, int x, int y)
{
    mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->collectible, y * TILE_SIZE, x * TILE_SIZE);
    game->collectibles++;
}

void    put_images(t_game *game)
{
	int	tailSize;
	
	tailSize = TILE_SIZE;
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr, "./assets/images/floor.xpm", &tailSize, &tailSize);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "./assets/images/wall.xpm", &tailSize, &tailSize);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, "./assets/images/player.xpm", &tailSize, &tailSize);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr, "./assets/images/exit.xpm", &tailSize, &tailSize);
	game->collectible = mlx_xpm_file_to_image(game->mlx_ptr, "./assets/images/collectible.xpm", &tailSize, &tailSize);
}

void	put_to_window(t_game *game)
{
	int	x;
	int	y;

	game->collectibles = 0;
	x = 0;
	while (x < game->map_h)
	{
		y = 0;
		while (game->map[x][y])
		{
			if(game->map[x][y] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->wall, y * TILE_SIZE, x * TILE_SIZE);
			if(game->map[x][y] == 'C')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->floor, y * TILE_SIZE, x * TILE_SIZE);
				put_collectable(game, x, y);
			}
			if(game->map[x][y] == 'P')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->floor, y * TILE_SIZE, x * TILE_SIZE);
				put_player(game, x, y);
			}
			if (game->map[x][y] == 'E')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->exit, y * TILE_SIZE, x * TILE_SIZE);
			}
			if (game->map[x][y] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->floor, y * TILE_SIZE, x * TILE_SIZE);
			y++;
		}
		x++;
	}
	
}