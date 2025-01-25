/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:57:57 by mberila           #+#    #+#             */
/*   Updated: 2025/01/25 10:36:48 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void f()
{
    system("leaks so_long");  // Check for memory leaks
    system("lsof | grep '^so_long'"); // Check for open file descriptors
}

int	main(int ac, char **av)
{
    t_game	*game;
	atexit(f);
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