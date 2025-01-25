/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:49:58 by mberila           #+#    #+#             */
/*   Updated: 2025/01/25 13:58:23 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	*load_texture(t_game *game, char *path)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!img)
	{
		ft_printf("Error\nFailed to load texture: %s\n", path);
		return (NULL);
	}
	return (img);
}

int	init_textures(t_game *game)
{
	game->wall = load_texture(game, "./mandatory/textures/wall.xpm");
	game->player_img = load_texture(game, "./mandatory/textures/player.xpm");
	game->collect_img = load_texture(game, "./mandatory/textures/collect.xpm");
	game->exit_img = load_texture(game, "./mandatory/textures/exit.xpm");
	game->floor= load_texture(game, "./mandatory/textures/floor.xpm");
	if (!game->wall || !game->player_img
		|| !game->collect_img || !game->exit_img
		|| !game->floor)
	{
		print_error(ERR_MLX);
		return (0);
	}
	return (1);
}