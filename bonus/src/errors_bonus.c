/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:04:45 by mberila           #+#    #+#             */
/*   Updated: 2025/01/23 18:08:57 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	handle_errors(t_game *g, const char *msg)
{
	ft_printf(RED "%d" RESET, msg);
	if (g)
		exit_point(g);
}

int	check_errors(t_game *game)
{
	if(game->map_h > 26 || game->map_w > 51)
		handle_errors(game, "\nThe map is too big\n");
	if (!is_rectangular(game))
		handle_errors(game, "\nError: Map is not rectangular\n");
	if_walls(game);
	character_valid(game);
	if (!validate_path (game))
		handle_errors(game, "\nError: Invalid path\n");
	return (0);
}
