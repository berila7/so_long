/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:37:02 by mberila           #+#    #+#             */
/*   Updated: 2025/01/25 10:37:11 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    free_game(t_game *game)
{
    int i;

    if (!game)
        return;

    if (game->map)
    {
        i = 0;
        while (i < game->height)
        {
            if (game->map[i])
                free(game->map[i]);
            i++;
        }
        free(game->map);
    }
    free(game);
}