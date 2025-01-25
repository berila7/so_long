/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:36:06 by mberila           #+#    #+#             */
/*   Updated: 2025/01/25 19:30:05 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	check_walls(t_game *game)
{
	int i;

	i = 0;
	while (i < game->width)
	{
		if(game->map[0][i] != WALL || game->map[game->height - 1][i] != WALL)
			return (0);
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != WALL || game->map[i][game->width - 1] != WALL)
			return (0);
		i++;
	}
	return (1);
}
static int	is_valid_char(char c)
{
	return (c == WALL || c == EMPTY || c == COLLECT
		|| c == EXIT || c == PLAYER || c == ENEMY);
}

static void	count_elements(t_game *game, char c)
{
	if(c == PLAYER)
		game->player++;
	if(c == EXIT)
		game->exit++;
	if(c == COLLECT)
		game->collect++;
}

static int	check_elemet_counts(t_game *game)
{
	if (game->player != 1)
	{
		print_error(ERR_PLAYER);
		return (0);
	}
	if (game->exit != 1)
	{
		print_error(ERR_EXIT);
		return (0);
	}
	if (game->collect < 1)
	{
		print_error(ERR_COLLECT);
		return (0);
	}
	return (1);
}
static int	check_map_chars(t_game *game)
{
	int	i;
	int	j;

	game->player = 0;
	game->exit = 0;
	game->collect = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while(j < game->width)
		{
			if(!is_valid_char(game->map[i][j]))
			{
				print_error(ERR_CHARS);
				return(0);
			}
			count_elements(game, game->map[i][j]);
			j++;
		}
		i++;
	}
	return (check_elemet_counts(game));
}

int	validate_map(t_game *game)
{
	if(!check_walls(game))
	{
		print_error(ERR_WALLS);
		return (0);
	}
	if (!check_map_chars(game))
        return (0);
	if (!check_path(game))
		return (0);
    return (1);
}