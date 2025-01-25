/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:25:02 by mberila           #+#    #+#             */
/*   Updated: 2025/01/25 19:37:18 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	is_blocked(t_game *game, int new_y)
{
	char	next_pos;
	
	next_pos = game->map[new_y][game->enemy_x];
	return (next_pos == WALL || next_pos == COLLECT || next_pos == EXIT);
}

void	update_enemy(t_game *game)
{
	int	new_y;
	
	find_char_pos(game, &game->enemy_x, &game->enemy_y, ENEMY);
	new_y = game->enemy_y + game->enemy_dir;

	if (is_blocked(game, new_y))
		game->enemy_dir *= -1;
	else
	{
		game->map[game->enemy_y][game->enemy_x] = EMPTY;
		game->map[new_y][game->enemy_x] = ENEMY;
	}
	if (game->map[new_y][game->enemy_x] == PLAYER)
	{
		ft_printf("\nGame Over! Enemy caught you!\n");
		close_window(game);
	}
}