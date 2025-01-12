/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:06:39 by mberila           #+#    #+#             */
/*   Updated: 2025/01/12 15:36:01 by mberila          ###   ########.fr       */
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
	int 		i;

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
	game->map_h = 0;
	while (1)
	{
		readmap = get_next_line(game->fd);
        if (!readmap)
            break;
        // Debug print
        // printf("Reading line: %s", readmap);
		if(!add_line(game, readmap))
        {
            free(readmap);
			break ;
        }
        // Debug print
        // printf("Added line %d to map\n", game->map_h);
	}
	close(game->fd);
    // Debug print
    // printf("Final map height: %d\n", game->map_h);
	game->map_w = width_of_map(game->map[0]);
	return (1);
}

t_pos    *get_char_pos(t_game *game, char c)
{
    int        i;
    int        j;
    t_pos    *pos;

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