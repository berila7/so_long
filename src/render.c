/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:17:03 by mberila           #+#    #+#             */
/*   Updated: 2025/01/11 10:21:20 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void    put_player(t_game *game, int height, int width)
{
    mlx_put_image_to_window(game->mlx_ptr, game->p, width * TILE_SIZE, height * TILE_SIZE
}