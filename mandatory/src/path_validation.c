/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:12:52 by mberila           #+#    #+#             */
/*   Updated: 2025/01/25 13:53:12 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**copy_map(t_game *game)
{
	char	**copy;
	int		i;

	copy = (char **)malloc (sizeof(char *) * (game->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while(i < game->height)
	{
		copy[i] = ft_strdup(game->map[i]);
		if (!copy[i])
		{
			free_map(copy, i);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	find_player_pos(t_game *game, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	*x = -1;
	*y = -1;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == PLAYER)
			{
				*y = i;
				*x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || x >= game->width || y < 0 || y >= game->height
		|| map[y][x] == WALL || map[y][x] == 'F')
		return ;
	if (map[y][x] == COLLECT)
		game->collect--;
	else if (map[y][x] == EXIT)
		game->exit--;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
}

int	check_path(t_game *game)
{
	char	**temp_map;
	int		player_x;
	int		player_y;
	int		collect_count;
	int		exit_count;

	temp_map = copy_map(game);
	if (!temp_map)
		return (0);
	find_player_pos(game, &player_x, &player_y);
	collect_count = game->collect;
	exit_count = game->exit;
	flood_fill(temp_map, player_x, player_y, game);
	if(game->collect != 0 || game->exit != 0)
	{
		free_map(temp_map, game->height);
		print_error(ERR_PATH);
		return (0);
	}
	game->collect = collect_count;
	game->exit = exit_count;
	free_map(temp_map, game->height);
	return (1);
}

