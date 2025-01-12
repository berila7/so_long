/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:06:39 by mberila           #+#    #+#             */
/*   Updated: 2025/01/12 10:18:53 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void draw_map(void *mlx, void *mlx_win)
// {
//     int     fd;
//     char    *line;
//     void    *wall;
//     void    *floor;
//     void    *item;
//     int     tailSize;
//     int     x;
//     int     y;

//     tailSize = TILE_SIZE;
//     wall = mlx_xpm_file_to_image(mlx, "./assets/images/wall.xpm", &tailSize, &tailSize);
//     floor = mlx_xpm_file_to_image(mlx, "./assets/images/floor.xpm", &tailSize, &tailSize);
//     item = mlx_xpm_file_to_image(mlx, "./assets/images/collectible.xpm", &tailSize, &tailSize);
//     fd = open("./assets/maps/map1.ber", O_RDONLY);
//     // line = get_next_line(fd);

//     if (fd < 0)
//     {
//         // Handle file open error
//         return;
//     }
    
//     if (!wall || !floor)
//     {
//         // Handle image loading error
//         close(fd);
//         return;
//     }

//     y = 0;
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         x = 0;
//         while (line[x])
//         {
//             if (line[x] == WALL)
//                 mlx_put_image_to_window(mlx, mlx_win, wall, tailSize * x, tailSize * y);
//             else if (line[x] == EMPTY)
//                 mlx_put_image_to_window(mlx, mlx_win, floor, tailSize * x, tailSize * y);
//             else if (line[x] == COLLECT)
//             {
//                 mlx_put_image_to_window(mlx, mlx_win, floor, tailSize * x, tailSize * y);
//                 mlx_put_image_to_window(mlx, mlx_win, item, tailSize * x, tailSize * y);
//             }
            
//             x++;
//         }
//         free(line); // Free the line after processing
//         y++;
//     }
//     close(fd); // Close the file descriptor
// }

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
        printf("Reading line: %s", readmap);
		if(!add_line(game, readmap))
        {
            free(readmap);
			break ;
        }
        // Debug print
        printf("Added line %d to map\n", game->map_h);
	}
	close(game->fd);
    // Debug print
    printf("Final map height: %d\n", game->map_h);
	game->map_w = width_of_map(game->map[0]);
	return (1);
}