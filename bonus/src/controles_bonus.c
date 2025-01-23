/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controles_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:37:36 by mberila           #+#    #+#             */
/*   Updated: 2025/01/23 16:45:57 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	change_pl_im(t_game *game, int key)
{
	if (key == KEYUP)
		game->player = game->pl_up;
	else if (key == KEYRIGHT)
		game->player = game->pl_r;
	else if (key == KEYLEFT)
		game->player = game->pl_l;
	else if (key == KEYDOWN)
	{
		game->player = game->pl_dw;
	}
}

static void	handle_cell_interaction(t_game *game, int y, int x)
{
	char	target_cell;

	target_cell = game->map[y][x];
	if (target_cell == '1')
		return ;
	if (target_cell == 'X')
	{
		ft_printf(RED"\nYou LOSE!\n"RESET);
		exit_point(game);
	}
	if (target_cell == 'E')
	{
		if (game->collectibles == 0)
		{
			ft_printf(RED"\nYou Have Won, Congrats!\n"RESET);
			exit_point(game);
		}
	}
	else if (target_cell == 'C')
	{
		game->collectibles--;
		game->map[y][x] = '0';
	}
}

static int	move_player(t_game *game, int y, int x, int key)
{
	handle_cell_interaction(game, y, x);
	if (game->map[y][x] == '1')
	{
		change_pl_im(game, key);
		return (0);
	}
	if (game->player_x != x || game->player_y != y)
	{
		game->counter++;
		ft_printf("Steps Taken: %i\n", game->counter);
		ft_printf("collectibles Remaining: %i\n", game->collectibles);
	}
	change_pl_im(game, key);
	game->player_x = x;
	game->player_y = y;
	return (1);
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
	move_player(game, y, x, key);
	return (1);
}
