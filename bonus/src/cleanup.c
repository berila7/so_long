/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:34:24 by mberila           #+#    #+#             */
/*   Updated: 2025/01/19 15:02:53 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void cleanup(t_game *game)
{
    int line;

    if (!game)
        return;
    if (game->mlx && game->mlx_win)
    {
        mlx_destroy_window(game->mlx, game->mlx_win);
        game->mlx_win = NULL;
    }
    if(game->player)
        mlx_destroy_image(game->mlx, game->player);
	if(game->wall)
        mlx_destroy_image(game->mlx, game->wall);
    if(game->collectible)
        mlx_destroy_image(game->mlx, game->collectible);
    if(game->exit)
        mlx_destroy_image(game->mlx, game->exit);
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
    if (game->mlx)
    {
         free(game->mlx);
         game->mlx = NULL;
    }
    free(game);
}
