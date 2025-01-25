/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:25:02 by mberila           #+#    #+#             */
/*   Updated: 2025/01/25 20:30:52 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	is_blocked(t_game *game, int new_y)
{
	char	next_pos;
	if (new_y < 0 || new_y >= game->height)
		return (1);
	next_pos = game->map[new_y][game->enemy_x];
	return (next_pos == WALL || next_pos == COLLECT || next_pos == EXIT);
}

static int	player_die(t_game *game, int new_y)
{
	int	player_x;
	int	player_y;

	find_char_pos(game, &player_x, &player_y, PLAYER);
	return (player_x == game->enemy_x && player_y == new_y);
}

void	update_enemy(t_game *game)
{
	int	new_y;
	
	game->enemy_timer++;
	if (game->enemy_timer < ENEMY_SPEED)
		return ;
	game->enemy_timer = 0;
	find_char_pos(game, &game->enemy_x, &game->enemy_y, ENEMY);
	new_y = game->enemy_y + game->enemy_dir;
	if (player_die(game, new_y))
	{
		print_error(ENE_CAUGHT);
		close_window(game);
		return ;
	}
	if (is_blocked(game, new_y))
		game->enemy_dir *= -1;
	else
	{
		game->map[game->enemy_y][game->enemy_x] = EMPTY;
		game->map[new_y][game->enemy_x] = ENEMY;
	}
}
