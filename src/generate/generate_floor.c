/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:24:04 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/18 15:58:56 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static t_map_tiles	get_random_floor_tile(void)
{
	int	rand;

	rand = sl_random_range(1, 8);
	if (rand == 1)
		return (GRASS_FLOOR);
	if (rand == 2)
		return (STEIN_FLOOR);
	return (EMPTY_FLOOR);
}

static void	fill_floor_tile(t_game *game, int y, int x)
{
	game->map.background_layer[y][x] = get_random_floor_tile();
}

void	sl_fill_floor_tiles(t_game *game)
{
	sl_tile_iterate(game, fill_floor_tile);
}
