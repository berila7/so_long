/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:46:30 by mberila           #+#    #+#             */
/*   Updated: 2025/01/19 16:00:32 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	exit_point(t_game *game)
{
	cleanup(game);
	exit(0);
}

static t_game	*init_game(int ac, char *av[])
{
	t_game	*game;
	t_pos	*p_pos;

	if (ac != 2)
		return (NULL);
	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	ft_bzero(game, sizeof(t_game));
	map_reading(game, av);
	check_errors(game);
	p_pos = get_char_pos(game, 'P');
	if (!p_pos)
	{
		free(game);
		return (NULL);
	}
	game->player_x = p_pos->x;
	game->player_y = p_pos->y;
	free(p_pos);
	return (game);
}

static int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		cleanup(game);
		return (0);
	}
	game->mlx_win = mlx_new_window(game->mlx, game->map_w * TILE_SIZE,
			game->map_h * TILE_SIZE, WIN_TITLE);
	if (!game->mlx_win)
	{
		cleanup(game);
		return (0);
	}
	put_images(game);
	put_to_window(game);
	return (1);
}

static void	start_game(t_game *game)
{
	mlx_key_hook(game->mlx_win, controls_working, game);
	mlx_hook(game->mlx_win, 17, 0, exit_point, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char *av[])
{
	t_game	*game;

	game = init_game(ac, av);
	if (!game)
	{
		printf("Error Initializing Game\n");
		return (1);
	}
	if (!init_mlx(game))
	{
		printf("Error Initializing MLX\n");
		return (1);
	}
	start_game(game);
	return (0);
}
