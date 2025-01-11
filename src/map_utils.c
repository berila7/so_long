/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:06:39 by mberila           #+#    #+#             */
/*   Updated: 2025/01/11 10:13:01 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_game *game, char *line)
{
	char		**temporary_map;
	size_t		i;

	if (!line)
		return (0);
	game->map_h++;
	
	temporary_map = (char **)malloc(sizeof(char *) * (game->map_h + 1));
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

int map_reading(t_game *game, char *av[])
{
    char	*readmap;
	
	game->fd = open(av[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	
	while (1)
	{
		readmap = get_next_line(game->fd);
		if(!add_line(game, readmap))
			break ;
	}
	close(game->fd);
	game->map_w = width_of_map(game->map[0]);
	return (1);
}