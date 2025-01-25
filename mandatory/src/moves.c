/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:49:33 by mberila           #+#    #+#             */
/*   Updated: 2025/01/25 13:12:41 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	update_player_position(t_game *game, int new_y, int new_x)
{
	int	old_x;
	int	old_y;
	
	find_player_pos(game, &old_x, &old_y);
	if (game->map[old_y][old_x] == PLAYER
		&& old_y == game->exit_pos_y
		&& old_x == game->exit_pos_x)
		game->map[old_y][old_x] = EXIT;
	else
		game->map[old_y][old_x] = EMPTY;
	game->map[new_y][new_x] = PLAYER;
}

static int	is_valid_move(t_game *game, int y, int x)
{
	if (game->map[y][x] == WALL)
		return (0);
	if (game->map[y][x] == EXIT && game->collect != 0)
	{
		game->exit_pos_x = x;
        game->exit_pos_y = y;
		return (1);
	}
	if (game->map[y][x] == COLLECT)
		game->collect--;
	if (game->map[y][x] == EXIT && game->collect == 0)
	{
		ft_printf("\nYou won");
		close_window(game);
	}
	return (1);
}

void	move_player(t_game *game, int keycode)
{
	int	x;
	int	y;
	int	new_y;
	int	new_x;

	find_player_pos(game, &x, &y);
	new_y = y;
	new_x = x;
	if (keycode == KEYUP)
		new_y = y - 1;
	else if (keycode == KEYDOWN)
		new_y = y + 1;
	else if (keycode == KEYLEFT)
		new_x = x - 1;
	else if (keycode == KEYRIGHT)
		new_x = x + 1;
	if (is_valid_move(game, new_y, new_x))
	{
		update_player_position(game, new_y, new_x);
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}
}