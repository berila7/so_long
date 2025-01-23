/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:19:32 by mberila           #+#    #+#             */
/*   Updated: 2025/01/23 16:45:38 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	draw_steps(t_game *g)
{
    char *steps;
    char *prefix;
    char *full_steps;

    steps = ft_itoa(g->counter);
    if(!steps)
    {
		ft_printf("Allocation failed");
		exit_point(g);
	}
    prefix = "Steps: ";
    full_steps = ft_strjoin(prefix, steps);
    free(steps);
    if(!full_steps)
         exit_point(g);
    mlx_string_put(g->mlx, g->mlx_win, 10, 10, 0xFFFFFF, full_steps);
    free(full_steps);

}
void	animate(t_game *g)
{
	g->frame_counter++;
	if (g->frame_counter >= DELAY)
	{
		g->frame_counter = 0;
		g->coin_frame = (g->coin_frame + 1) % 5;
		g->enemy_frame = (g->enemy_frame + 1) % 5;
	}
}