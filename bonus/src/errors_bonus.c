/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:04:45 by mberila           #+#    #+#             */
/*   Updated: 2025/01/23 16:46:00 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_errors(t_game *game)
{
	if(game->map_h > 26 || game->map_w > 51)
	{
		ft_printf("The map is too big");
		exit_point(game);
	}
	if (!is_rectangular (game))
	{
		ft_printf(RED "\nError: Map is not rectangular\n" RESET);
		exit_point (game);
	}
	if_walls(game);
	character_valid(game);
	if (!validate_path (game))
	{
		ft_printf(RED "\nError: Invalid path\n" RESET);
		exit_point (game);
	}
	return (0);
}
