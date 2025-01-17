/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:34:24 by mberila           #+#    #+#             */
/*   Updated: 2025/01/17 12:04:52 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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