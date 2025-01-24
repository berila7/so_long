/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:57:57 by mberila           #+#    #+#             */
/*   Updated: 2025/01/24 18:19:05 by mberila          ###   ########.fr       */
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

int	main(int ac, char **av)
{
    t_game	*game;

    if (ac != 2)
    {
        print_error(ERR_MAP_ARG);
        return (1);
    }
    game = init_game();
    if (!game)
        return (1);
    if (!read_map(game, av[1]))
    {
        free_game(game);
        return (1);
    }
    if (!validate_map(game))
    {
        free_game(game);
        return (1);
    }
    free_game(game);
    return (0);
}