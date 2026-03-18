/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:24:00 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/18 15:58:56 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static int	is_horizontal_wall(t_game *game, int y, int x)
{
	char	**grid;

	if (y + 1 >= game->map.height)
		return (1);
	grid = game->map.grid;
	if (grid[y + 1][x] != '1')
		return (1);
	return (0);
}

static t_map_tiles	get_wall_tile(t_game *game, int y, int x)
{
	if (is_horizontal_wall(game, y, x))
		return (HORIZONTAL_WALL);
	return (VERTICAL_WALL);
}

static void	fill_wall_tile(t_game *game, int y, int x)
{
	char	**grid;

	grid = game->map.grid;
	if (grid[y][x] == '1')
		game->map.background_layer[y][x] = get_wall_tile(game, y, x);
}

void	sl_fill_wall_tiles(t_game *game)
{
	sl_tile_iterate(game, fill_wall_tile);
}
