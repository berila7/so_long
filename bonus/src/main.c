/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:46:30 by mberila           #+#    #+#             */
/*   Updated: 2025/01/19 15:03:12 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int exit_point(t_game *game)
{
    cleanup(game);
    exit(0);
}

int main(int ac, char *av[])
{
    t_game *game;

    if (ac != 2)
        return (0);
    game = malloc(sizeof(t_game));
    ft_bzero(game,sizeof(t_game));
    map_reading(game, av);
    check_errors(game);
    t_pos *p_pos = get_char_pos(game, 'P');
    game->player_x = p_pos->x;
    game->player_y = p_pos->y;
    game->mlx = mlx_init();
    if (!game->mlx)
        exit_point(game);
    game->mlx_win = mlx_new_window(game->mlx, game->map_w * TILE_SIZE, game->map_h * TILE_SIZE, WIN_TITLE);
    if (!game->mlx_win)
        exit_point(game);

    printf("\nMap width : %d\n", game->map_w);
    printf("\nMap height: %d\n", game->map_h);
    put_images(game);
    put_to_window(game);
    mlx_key_hook(game->mlx_win, controls_working, game);
    mlx_hook(game->mlx_win, 17, 0, exit_point, game);
    mlx_loop(game->mlx);
    return (0);
}
