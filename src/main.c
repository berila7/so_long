/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:46:30 by mberila           #+#    #+#             */
/*   Updated: 2025/01/12 10:19:29 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int exit_point(t_game *game)
{
    int line;
    
    line = 0;
    if (game->mlx)
        mlx_destroy_window(game->mlx, game->mlx_win);
    free(game->mlx);
    while (line < game->map_h - 1)
        free(game->map[line++]);
    free(game->map);
    exit(0);
}

int main(int ac, char *av[])
{
    t_game *game;
    
    if(ac != 2)
        return (0);
    game = (t_game *)malloc(sizeof(t_game));
    if (!game)
        return (1);
    map_reading(game, av);
    game->mlx = mlx_init();
    if(game->mlx == NULL)
        return (1);
    game->mlx_win = mlx_new_window(game->mlx, game->map_w * TILE_SIZE, game->map_h * TILE_SIZE, "King's Treasure");
    // Verify window creation succeeds
    if (game->mlx_win == NULL)
        return (1);

    printf("\nMap width : %d", game->map_w);
	printf("\nMap height: %d\n", game->map_h);
    put_images(game);
    put_to_window(game);
    mlx_key_hook(game->mlx_win, controls_working, game);
    mlx_hook(game->mlx_win, 17, 0, (void *)exit, 0);
    // draw_map(game.mlx, game.mlx_win);
    mlx_loop(game->mlx);
    mlx_destroy_window(game->mlx, game->mlx_win);
    free(game->mlx);
    free(game);
    return (0);
}
