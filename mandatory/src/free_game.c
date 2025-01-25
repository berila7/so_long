/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:37:02 by mberila           #+#    #+#             */
/*   Updated: 2025/01/25 14:05:30 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static	void	free_textures(t_game *game)
{
	if (!game->mlx)
		return ;
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->collect_img)
		mlx_destroy_image(game->mlx, game->collect_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
}

void    free_game(t_game *game)
{
    if (!game)
        return;
	if (game->mlx)
	{
		free_textures(game);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		free(game->mlx);
	}
    if (game->map)
        free_map(game->map, game->height);
    free(game);
}