/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:37:36 by mberila           #+#    #+#             */
/*   Updated: 2025/01/12 10:12:56 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	move_player(t_game *game, int new_x, int new_y)
{
    if (new_x < 0 || new_x >= game->map_w || new_y < 0 || new_y >= game->map_h)
        return (0);
    
    char target_cell = game->map[new_y][new_x];
    
    if (target_cell == '1')
        return (0);
    else if (target_cell == 'E')
    {
        if (game->collectables != 0)
            return (0);
        printf("\nYou Have Won, Congrats!\n");
        exit_point(game);
    }
    else if (target_cell == 'C')
    {
        game->collectables--; /* Collect the item */
    }
    game->map[game->player_y][game->player_x] = '0'; /* Clear old position */
    game->player_x = new_x;
    game->player_y = new_y;
    game->map[new_y][new_x] = 'P'; /* Place player in new position */
    game->counter++;
    printf("Steps Taken: %i\n", game->counter);
    printf("Collectables Remaining: %i\n", game->collectables);
    return (1);
}

int	controls_working(int key, t_game *game)
{
    int new_x;
    int new_y;
    
    new_x = game->player_x;
    new_y = game->player_y;
    if (key == 53)
        exit_point(game);
    if (key == 13)      /* W key - Move up */
        new_y--;
    else if (key == 1)  /* S key - Move down */
        new_y++;
    else if (key == 0)  /* A key - Move left */
        new_x--;
    else if (key == 2)  /* D key - Move right */
        new_x++;
    if (move_player(game, new_x, new_y))
        put_to_window(game);
    return (1);
}