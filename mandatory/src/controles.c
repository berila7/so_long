/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:37:36 by mberila           #+#    #+#             */
/*   Updated: 2025/01/17 16:31:33 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	move_player(t_game *game, int y, int x)
{
    char target_cell = game->map[y][x];
    
    if (target_cell == '1')
        return (0);
    if (target_cell == 'E')
    {
        if (game->collectibles == 0)
        {
            printf("\nYou Have Won, Congrats!\n");
            exit_point(game);
        }
    }
    else if (target_cell == 'C')
    {
        game->collectibles--; /* Collect the item */
        game->map[y][x] = '0';
    }
    if (game->player_x != x || game->player_y != y)
    {
        game->counter++;
        printf("Steps Taken: %i\n", game->counter);
        printf("collectibles Remaining: %i\n", game->collectibles);
    }
    game->player_x = x;
    game->player_y = y;
    return (1);
}

int	controls_working(int key, t_game *game)
{
    int y;
    int x;
    
    x = game->player_x;
    y = game->player_y;
    if (key == 53)
        exit_point(game);
    if (key == 13)      /* W key - Move up */
        y--;
    else if (key == 1)  /* S key - Move down */
        y++;
    else if (key == 0)  /* A key - Move left */
        x--;
    else if (key == 2)  /* D key - Move right */
        x++;
    if (move_player(game, y, x))
        put_to_window(game);
    return (1);
}