/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:37:02 by mberila           #+#    #+#             */
/*   Updated: 2025/01/25 19:41:43 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
static void	free_basic_textures(t_game *game)
{
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->collect_img)
		mlx_destroy_image(game->mlx, game->collect_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->enemy_img)
		mlx_destroy_image(game->mlx, game->enemy_img);
}

static void	free_player_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->player_frames[i])
			mlx_destroy_image(game->mlx, game->player_frames[i]);
		i++;
	}
}

static	void	free_textures(t_game *game)
{
	int	i;

	if (!game->mlx)
		return ;
	free_basic_textures(game);
	free_player_textures(game);
	i = 0;
	while (i < ANIMATION_FRAMES)
	{
		if (game->collect_frames[i])
			mlx_destroy_image(game->mlx, game->collect_frames[i]);
		i++;
	}
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
