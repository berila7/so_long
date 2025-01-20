/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:06:39 by mberila           #+#    #+#             */
/*   Updated: 2025/01/19 16:35:28 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	return (width);
}

static int	add_line(t_game *game, char *line)
{
	char	**temporary_map;
	int		i;

	if (!line)
		return (0);
	game->map_h++;
	temporary_map = (char **)malloc(sizeof(char *) * (game->map_h + 1));
	if (!temporary_map)
		return (0);
	temporary_map[game->map_h] = NULL;
	i = 0;
	while (i < game->map_h - 1)
	{
		temporary_map[i] = game->map[i];
		i++;
	}
	temporary_map[i] = line;
	if (game->map)
		free(game->map);
	game->map = temporary_map;
	return (1);
}

static int	process_map_lines(t_game *game, char *readmap)
{
	char	*trimmed_line;

	while (readmap)
	{
		trimmed_line = ft_strtrim(readmap, "\n");
		free(readmap);
		readmap = trimmed_line;
		printf("Reading line: %s\n", readmap);
		if (!add_line(game, readmap))
		{
			free(readmap);
			break ;
		}
		readmap = get_next_line(game->fd);
	}
	close(game->fd);
	game->map_w = width_of_map(game->map[0]);
	return (1);
}

int	map_reading(t_game *game, char *av[])
{
	char	*readmap;

	game->fd = open(av[1], O_RDONLY);
	if (game->fd < 0)
	{
		printf(RED "\nError: Could not open file\n" RESET);
		return (0);
	}
	readmap = get_next_line(game->fd);
	if (!readmap)
	{
		printf(RED"Error: your map is EMPTY"RESET);
		exit_point(game);
	}
	game->map_h = 0;
	return (process_map_lines(game, readmap));
}

t_pos	*get_char_pos(t_game *game, char c)
{
	int		i;
	int		j;
	t_pos	*pos;

	pos = malloc(sizeof(t_pos));
	if (!pos)
		return (NULL);
	pos->x = -1;
	pos->y = -1;
	i = 0;
	while (i < game->map_h)
	{
		j = 0;
		while (j < game->map_w)
		{
			if (game->map[i][j] == c)
				return (pos->y = i, pos->x = j, pos);
			j++;
		}
		i++;
	}
	return (pos);
}
