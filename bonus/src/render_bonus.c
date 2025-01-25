/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:12:51 by mberila           #+#    #+#             */
/*   Updated: 2025/01/25 19:40:44 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img,
		x * TILE_SIZE, y * TILE_SIZE);
}

static void	render_tile(t_game *game, int x, int y)
{
	char	tile;
	
	tile = game->map[y][x];
	put_image(game, game->floor, x, y);
	if (tile == WALL)
		put_image(game, game->wall, x, y);
	else if (tile == PLAYER)
		put_image(game, game->player_img, x, y);
	else if (tile == COLLECT)
		put_image(game, game->collect_frames[game->collect_current_frame], x, y);
	else if (tile == EXIT)
		put_image(game, game->exit_img, x, y);
	else if (tile == ENEMY)
		put_image(game, game->enemy_img, x, y);
}

int	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
	return (1);	
}