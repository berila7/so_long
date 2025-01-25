/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:57:57 by mberila           #+#    #+#             */
/*   Updated: 2025/01/25 12:07:28 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void f()
{
    system("leaks so_long");  // Check for memory leaks
    system("lsof | grep '^so_long'"); // Check for open file descriptors
}

static int	setup_game(t_game *game, char *map_path)
{
	if (!read_map(game, map_path))
        return (0);
    if (!validate_map(game))
        return (0);
	if (!init_mlx(game))
		return (0);
	if (!init_game_window(game))
		return (0);
	if (!init_textures(game))
		return (0);
	return (1);
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
	if (!setup_game(game, av[1]))
	{
		free_game(game);
		return (1);
	}
	mlx_loop(game->mlx);
    free_game(game);
    return (0);
}
