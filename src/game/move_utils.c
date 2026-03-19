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

static int	is_movable_tile(t_game *game, int ny, int nx)
{
	char	tile;

	tile = game->map.background_layer[ny][nx];
	if (tile == HORIZONTAL_WALL || tile == VERTICAL_WALL)
		return (0);
	return (1);
}

static int	is_door_block_move(t_game *game, int y, int x)
{
	if (game->map.interactive_layer[y][x] == EXIT_CLOSED)
		return (1);
	return (0);
}

int	sl_can_move(t_game *game, int nx, int ny)
{
	if (nx < 0 || ny < 0)
		return (0);
	if (nx >= game->map.width || ny >= game->map.height)
		return (0);
	if (!is_movable_tile(game, ny, nx))
		return (0);
	if (is_door_block_move(game, ny, nx))
		return (0);
	return (1);
}
