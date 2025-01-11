/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:46:30 by mberila           #+#    #+#             */
/*   Updated: 2025/01/11 10:16:38 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int exit_point(t_game *game)
{
    size_t line;
    
    line = 0;
    if (game->mlx_ptr)
        mlx_destroy_window(game->mlx_ptr, game->mlx_win);
    free(game->mlx_ptr);
    while (line < game->map_h - 1)
        free(game->map[line++]);
    free(game->map);
    exit(0);
}

int main(int ac, char *av[])
{
    t_game game;
    
    if(ac != 2)
        return (0);
    ft_memeset(&game, 0, sizeof(t_game));
    game.mlx_ptr = mlx_init();
    if(game.mlx_ptr == NULL)
        return (1);
    game.mlx_win = mlx_new_window(game.mlx_ptr, map_width() * TILE_SIZE, map_height() * TILE_SIZE, "King's Treasure");

    printf("\nMap width : %d", map_width());
	printf("\nMap height: %d\n", map_height());

    draw_map(game.mlx_ptr, game.mlx_win);
    mlx_loop(game.mlx_ptr);
    mlx_destroy_window(game.mlx_ptr, game.mlx_win);
    free(game.mlx_ptr);
    return (0);
}
