/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:04:45 by mberila           #+#    #+#             */
/*   Updated: 2025/01/23 16:28:48 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_errors(t_game *game)
{
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
