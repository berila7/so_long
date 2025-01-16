/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:34:24 by mberila           #+#    #+#             */
/*   Updated: 2025/01/16 14:40:27 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void cleanup(t_game *game)
{
    int line;

    // if (game && game->mlx && game->mlx_win)
    //     mlx_destroy_window(game->mlx, game->mlx_win);
    if (game && game->map)
    {
        line = 0;
        while (line < game->map_h)
        {
            if (game->map[line])
                free(game->map[line]);
            line++;
        }
        free(game->map);
    }
    // if (game && game->mlx)
    //     free(game->mlx);
    if (game)
        free(game);
}