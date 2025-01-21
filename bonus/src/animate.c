/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:19:32 by mberila           #+#    #+#             */
/*   Updated: 2025/01/21 12:01:30 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	animate(t_game *g)
{
	g->frame_counter++;
	if (g->frame_counter >= DELAY)
	{
		g->frame_counter = 0;
		g->coin_frame = (g->coin_frame + 1) % 5;
	}
}

void	draw_steps(t_game *game)
{
    char *steps;
    char *prefix;
    char *full_steps;

    steps = ft_itoa(game->counter);
    if(!steps)
    {
		printf("Allocation failed");
		exit_point(game);
	}
    prefix = "Steps: ";
    full_steps = ft_strjoin(prefix, steps);
    free(steps);
    if(!full_steps)
         exit_point(game);
    mlx_string_put(game->mlx, game->mlx_win, 10, 10, 0xFFFFFF, full_steps);
    free(full_steps);

}
