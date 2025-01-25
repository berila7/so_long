/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:57:57 by mberila           #+#    #+#             */
/*   Updated: 2025/01/25 20:38:31 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

// void f()
// {
//     system("leaks so_long");  // Check for memory leaks
//     system("lsof | grep '^so_long'"); // Check for open file descriptors
// }

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESCKEY)
		close_window(game);
	if (keycode == KEYUP || keycode == KEYDOWN
		|| keycode == KEYLEFT || keycode == KEYRIGHT)
	{
		move_player(game, keycode);
		render_map(game);
	}
	return (0);
}

int	close_window(t_game *game)
{
	if (game)
		free_game(game);
	exit(0);
	return (0);
}

int	loop_hook(t_game *game)
{
	update_animations(game);
	update_enemy(game);
	render_map(game);
	return(0);
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
	init_animations(game);
	if (!render_map(game))
		return (0);
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, ON_DESTROY, NO_EVENT_MASK, close_window, game);
	mlx_loop_hook(game->mlx, loop_hook, game);
	return (1);
}

int	main(int ac, char **av)
{
    t_game	*game;
	// atexit(f);
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
    return (0);
}
