/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:27:20 by mberila           #+#    #+#             */
/*   Updated: 2025/01/25 19:41:09 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	init_game_window(t_game *game)
{
	if(!game->width || !game->height)
	{
		print_error(ERR_DIMEN);
		return (0);
	}
	game->win = mlx_new_window(game->mlx,
		game->width * TILE_SIZE,
		game->height * TILE_SIZE,
		"so_long");
	if (!game->win)
	{
		print_error(ERR_MLX);
		return (0);
	}
	return (1);
}

t_game    *init_game(void)
{
    t_game    *game;

    game = (t_game *)malloc(sizeof(t_game));
    if (!game)
    {
        print_error(MALLOC_FAIL);
        return (NULL);
    }
    ft_memset(game, 0, sizeof(t_game));
	game->enemy_dir = 1;
    return (game);
}

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		print_error(ERR_MLX);
		return (0);
	}
	return (1);
}
