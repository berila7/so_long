/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:33:53 by mberila           #+#    #+#             */
/*   Updated: 2025/01/20 16:34:56 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static char	**allocate_visited_array(t_game *game)
{
	int		i;
	char	**visited;

	visited = (char **)malloc(sizeof(char *) * game->map_h);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < game->map_h)
	{
		visited[i] = (char *)calloc(game->map_w, sizeof(char));
		if (!visited[i])
		{
			while (i > 0)
				free(visited[--i]);
			free(visited);
			return (NULL);
		}
		i++;
	}
	return (visited);
}

static t_fill	*init_flood_fill(t_game *game)
{
	t_fill	*fill;

	fill = (t_fill *)malloc(sizeof(t_fill));
	if (!fill)
		return (NULL);
	fill->visited = allocate_visited_array(game);
	if (!fill->visited)
	{
		free(fill);
		return (NULL);
	}
	fill->collectibles_reached = 0;
	fill->exit_reached = 0;
	return (fill);
}

// // Recursive flood fill to validate path
static void	flood_fill(t_game *game, t_fill *fill, int y, int x)
{
	// Check boundaries and walls
	if (y < 0 || y >= game->map_h || x < 0 || x >= game->map_w
		|| game->map[y][x] == '1' || fill->visited[y][x])
		return ;
	fill->visited[y][x] = 1;
	// Count reachable collectibles and exit
	if (game->map[y][x] == 'C')
		fill->collectibles_reached++;
	if (game->map[y][x] == 'E')
		fill->exit_reached = 1;
	// Recursive calls in all directions
	flood_fill(game, fill, y - 1, x); // Up
	flood_fill(game, fill, y + 1, x); // Down
	flood_fill(game, fill, y, x - 1); // Left
	flood_fill(game, fill, y, x + 1); // Right
}

// // Validate path from player to all collectibles and exit

static int	perform_flood_fill(t_game *game, int player_y, int player_x)
{
	t_fill	*fill;
	int		i;
	int		valid;

	fill = init_flood_fill(game);
	if (!fill)
		return (0);
	flood_fill(game, fill, player_y, player_x);
	valid = (fill->collectibles_reached == game->collectibles
			&& fill->exit_reached);
	i = 0;
	while (i < game->map_h)
	{
		free(fill->visited[i]);
		i++;
	}
	free(fill->visited);
	free(fill);
	return (valid);
}

int	validate_path(t_game *game)
{
	int		i;
	int		player_y;
	int		player_x;
	char	*pos;

	player_y = -1;
	player_x = -1;
	i = 0;
	// Find player position
	while (i < game->map_h)
	{
		pos = ft_strchr(game->map[i], 'P');
		if (pos)
		{
			player_y = i;
			player_x = pos - game->map[i];
			break ;
		}
		i++;
	}
	if (player_y == -1 || player_x == -1)
		return (0);
	return (perform_flood_fill(game, player_y, player_x));
}
