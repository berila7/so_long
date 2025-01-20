/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:19:32 by mberila           #+#    #+#             */
/*   Updated: 2025/01/20 21:36:45 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

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
