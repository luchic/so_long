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
	if (tile == EXIT_CLOSED)
		return (0);
	return (1);
}

static void	replase_clased_door(t_game *game, int y, int x)
{
	if (game->map.background_layer[y][x] == EXIT_CLOSED)
		game->map.background_layer[y][x] = EXIT_OPEN;
}

static void	setup_open_door(t_game *game)
{
	sl_tile_iterate(game, replase_clased_door);
}

int	sl_can_move(t_game *game, int nx, int ny)
{
	if (nx < 0 || ny < 0)
		return (0);
	if (nx >= game->map.width || ny >= game->map.height)
		return (0);
	if (!is_movable_tile(game, ny, nx))
		return (0);
	return (1);
}

void	sl_try_collect(t_game *game, int nx, int ny)
{
	if (game->map.interactive_layer[ny][nx] == COLLECTABLE)
	{
		game->player.collected++;
		game->map.interactive_layer[ny][nx] = EMPTY;
		if (game->player.collected == game->map.collectibles)
			setup_open_door(game);
	}
}
