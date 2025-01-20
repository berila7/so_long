/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:37:36 by mberila           #+#    #+#             */
/*   Updated: 2025/01/19 15:49:28 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	handle_cell_interaction(t_game *game, int y, int x)
{
	char	target_cell;

	target_cell = game->map[y][x];
	if (target_cell == '1')
		return ;
	if (target_cell == 'E')
	{
		if (game->collectibles == 0)
		{
			printf("\nYou Have Won, Congrats!\n");
			exit_point(game);
		}
	}
	else if (target_cell == 'C')
	{
		game->collectibles--;
		game->map[y][x] = '0';
	}
}

static int	update_player_position(t_game *game, int y, int x)
{
	if (game->player_x != x || game->player_y != y)
	{
		game->counter++;
		printf("Steps Taken: %i\n", game->counter);
		printf("collectibles Remaining: %i\n", game->collectibles);
	}
	game->player_x = x;
	game->player_y = y;
	return (1);
}

static int	move_player(t_game *game, int y, int x)
{
	handle_cell_interaction(game, y, x);
	if (game->map[y][x] == '1')
		return (0);
	return (update_player_position(game, y, x));
}

int	controls_working(int key, t_game *game)
{
	int	y;
	int	x;

	x = game->player_x;
	y = game->player_y;
	if (key == ESCKEY)
		exit_point(game);
	if (key == KEYUP)
		y--;
	else if (key == KEYDOWN)
		y++;
	else if (key == KEYLEFT)
		x--;
	else if (key == KEYRIGHT)
		x++;
	if (move_player(game, y, x))
		put_to_window(game);
	return (1);
}
