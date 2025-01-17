/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:04:45 by mberila           #+#    #+#             */
/*   Updated: 2025/01/17 16:31:33 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_fill *init_flood_fill(t_game *game)
{
    t_fill *fill;
    int i;

    fill = (t_fill *)malloc(sizeof(t_fill));
    if (!fill)
        return (NULL);
    fill->visited = (char **)malloc(sizeof(char *) * game->map_h);
    if (!fill->visited)
    {
        free(fill);
        return (NULL);
    }
    i = 0;
    while (i < game->map_h)
    {
        fill->visited[i] = (char *)calloc(game->map_w, sizeof(char));
        if (!fill->visited[i])
        {
            while (i > 0)
                free(fill->visited[--i]);
            free(fill->visited);
            free(fill);
            return (NULL);
        }
        i++;
    }
    fill->collectibles_reached = 0;
    fill->exit_reached = 0;
    return (fill);
}

// // Recursive flood fill to validate path
static void flood_fill(t_game *game, t_fill *fill, int y, int x)
{
    // Check boundaries and walls
    if (y < 0 || y >= game->map_h || x < 0 || x >= game->map_w ||
        game->map[y][x] == '1' || fill->visited[y][x])
        return;

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
static int validate_path(t_game *game)
{
    t_fill *fill;
    int i;
    int player_y = -1;
    int player_x = -1;
    int valid;

    // Find player position
    for (i = 0; i < game->map_h; i++)
    {
        char *pos = ft_strchr(game->map[i], 'P');
        if (pos)
        {
            player_y = i;
            player_x = pos - game->map[i];
            break;
        }
    }

    fill = init_flood_fill(game);
    if (!fill)
        return (0);

    // Perform flood fill from player position
    flood_fill(game, fill, player_y, player_x);

    // Check if all collectibles and exit are reachable
    valid = (fill->collectibles_reached == game->collectibles && 
             fill->exit_reached);

    // Cleanup
    for (i = 0; i < game->map_h; i++)
        free(fill->visited[i]);
    free(fill->visited);
    free(fill);

    return (valid);
}

static int is_rectangular(t_game *game)
{
    int i;
    int len;

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

static int horizontalwall(t_game *game)
{
    int j;

    // Check first and last row
    for (j = 0; j < game->map_w; j++)
    {
        if (game->map[0][j] != '1' || game->map[game->map_h - 1][j] != '1')
            return (0);
    }
    return (1);
}

static int verticalwall(t_game *game)
{
    int y;

    for (y = 0; y < game->map_h; y++)
    {
        if (game->map[y][0] != '1' || game->map[y][game->map_w - 1] != '1')
            return (0);
    }
    return (1);
}

static void if_walls(t_game *game)
{
    if (!verticalwall(game) || !horizontalwall(game))
    {
        printf(RED "\nError: Map is missing walls\n" RESET);
        exit_point(game);
    }
}

static void count_checker(t_game *game, int height, int width)
{
    char current = game->map[height][width];
    
    // Valid characters check
    if (current != '1' && current != '0' && current != 'P' &&
        current != 'E' && current != 'C' && current != '\n')
    {
        printf("\nError: Invalid character '%c' at position [%d][%d]\n", 
               current, height, width);
        exit_point(game);
    }

    // Count game elements
    if (current == 'C')
        game->collectibles++;
    else if (current == 'P')
        game->player_count++;
    else if (current == 'E')
        game->exit_count++;
}

static void character_valid(t_game *game)
{
    int height, width;

    game->collectibles = 0;
    game->player_count = 0;
    game->exit_count = 0;

    for (height = 0; height < game->map_h; height++)
    {
        for (width = 0; width < game->map_w; width++)
        {
            count_checker(game, height, width);
        }
    }

    if (game->player_count != 1 || game->collectibles < 1 || 
        game->exit_count != 1)
    {
        printf("\nError: Invalid map configuration\n");
        printf("Required: 1 player, at least 1 collectible, 1 exit\n");
        printf("Found: %d player(s), %d collectible(s), %d exit(s)\n",
               game->player_count, game->collectibles, game->exit_count);
        exit_point(game);
    }
}

int check_errors(t_game *game)
{
    // Check if map is rectangular
    if (!is_rectangular(game))
    {
        printf(RED "\nError: Map is not rectangular\n" RESET);
        exit_point(game);
    }
    if_walls(game);
    character_valid(game);
    if (!validate_path(game))
    {
        printf(RED "\nError: Invalid path - not all collectibles or exit are reachable\n" RESET);
        exit_point(game);
    }
    return (0);
}

