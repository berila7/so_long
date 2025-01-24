/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:36:06 by mberila           #+#    #+#             */
/*   Updated: 2025/01/23 18:58:02 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	is_rectangular(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	while (i < game->map_h)
	{
		len = ft_strlen(game->map[i]);
		if (len != game->map_w)
			return (-1);
		i++;
	}
	return (1);
}

static int	validate_map_borders(t_game *game)
{
	int	y;
	int	j;

	j = 0;
	while (j < game->map_w)
	{
		if (game->map[0][j] != '1' || game->map[game->map_h - 1][j] != '1')
			return (0);
		j++;
	}
	y = 0;
	while (y < game->map_h)
	{
		if (game->map[y][0] != '1' || game->map[y][game->map_w - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

void	if_walls(t_game *game)
{
	if (!validate_map_borders(game))
	{
		ft_printf(RED "\nError: Map is missing walls\n" RESET);
		exit_point(game);
	}
}

static void	count_checker(t_game *game, int height, int width)
{
	char	current;

	current = game->map[height][width];
	if (current != '1' && current != '0' && current != 'P'
		&& current != 'E' && current != 'C' && current != 'X' && current != '\n')
	{
		ft_printf(RED"\nError: Invalid character '%c' at position [%d][%d]\n",
			current, height, width);
		exit_point(game);
	}
	if (current == 'C')
		game->collectibles++;
	else if (current == 'P')
		game->player_count++;
	else if (current == 'E')
		game->exit_count++;
	else if (current == 'X')
		game->enemy_count++;
}

void	character_valid(t_game *g)
{
	int	height;
	int	width;

	g->collectibles = 0;
	g->player_count = 0;
	g->exit_count = 0;
	g->enemy_count = 0;
	height = 0;
	while (height < g->map_h)
	{
		width = 0;
		while (width < g->map_w)
		{
			count_checker(g, height, width);
			width++;
		}
		height++;
	}
	if (g->player_count != 1 || g->collectibles < 1
		|| g->exit_count != 1 || g->enemy_count != 1)
	{
		ft_printf("\nError: Invalid map configuration\n");
		ft_printf("Found: %d P, %d C, %d E, %d X\n",
			g->player_count, g->collectibles, g->exit_count, g->enemy_count);
		exit_point(g);
	}
}
