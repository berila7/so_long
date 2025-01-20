/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:34:24 by mberila           #+#    #+#             */
/*   Updated: 2025/01/19 15:38:09 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	cleanup_mlx(t_game *game)
{
	if (!game || !game->mlx)
		return ;
	if (game->mlx_win)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		game->mlx_win = NULL;
	}
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->collectible)
		mlx_destroy_image(game->mlx, game->collectible);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	free(game->mlx);
	game->mlx = NULL;
}

void	cleanup_game_data(t_game *game)
{
	int	line;

	if (!game)
		return ;
	if (game->map)
	{
		line = 0;
		while (line < game->map_h)
		{
			if (game->map[line])
			{
				free(game->map[line]);
				game->map[line] = NULL;
			}
			line++;
		}
		free(game->map);
		game->map = NULL;
	}
	free(game);
}

void	cleanup(t_game *game)
{
	cleanup_mlx(game);
	cleanup_game_data(game);
}
