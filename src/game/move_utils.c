/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:00:00 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/16 12:00:00 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	sl_can_move(t_game *game, int nx, int ny)
{
	if (nx < 0 || ny < 0)
		return (0);
	if (nx >= game->map.width || ny >= game->map.height)
		return (0);
	if (game->map.grid[ny][nx] == '1')
		return (0);
	return (1);
}

void	sl_try_collect(t_game *game, int nx, int ny)
{
	if (game->map.grid[ny][nx] == 'C')
	{
		game->player.collected++;
		game->map.grid[ny][nx] = '0';
	}
}
