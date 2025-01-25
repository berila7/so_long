/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:49:58 by mberila           #+#    #+#             */
/*   Updated: 2025/01/25 20:19:50 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	*load_texture(t_game *game, char *path)
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

static int	init_player_textures(t_game *game)
{
	game->player_frames[P_RIGHT] = load_texture(game,
		"./bonus/textures/player/pl_r.xpm");
	game->player_frames[P_LEFT] = load_texture(game,
		"./bonus/textures/player/pl_l.xpm");
	game->player_frames[P_UP] = load_texture(game,
		"./bonus/textures/player/pl_up.xpm");
	game->player_frames[P_DOWN] = load_texture(game,
		"./bonus/textures/player/pl_dw.xpm");
	game->player_direction = P_DOWN;
	game->player_img = game->player_frames[game->player_direction];
	return (game->player_frames[P_RIGHT] && game->player_frames[P_LEFT]
		&& game->player_frames[P_UP] && game->player_frames[P_DOWN]);
}
static int	init_basic_textures(t_game *game)
{
	game->wall = load_texture(game, "./bonus/textures/wall.xpm");
	game->collect_img = load_texture(game, "./bonus/textures/collect.xpm");
	game->exit_img = load_texture(game, "./bonus/textures/exit.xpm");
	game->floor = load_texture(game, "./bonus/textures/floor.xpm");
	game->enemy_img = load_texture(game, "./bonus/textures/enemy/e_1.xpm");
	return (game->wall && game->floor && game->enemy_img
			&& game->collect_img && game->exit_img);
}

int	init_textures(t_game *game)
{
	if (!init_basic_textures(game) || !init_player_textures(game))
	{
		print_error(ERR_MLX);
		return (0);
	}
	return (1);
}
