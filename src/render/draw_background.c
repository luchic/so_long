/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:14:10 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/19 10:59:22 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static void	fill_background_tile(t_game *game, int y, int x)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	if (game->map.background_layer[y][x] == HORIZONTAL_WALL)
		sl_insert_tile(game, game->img.background_frame,
			game->textures.wall_border, pos);
	else if (game->map.background_layer[y][x] == VERTICAL_WALL)
		sl_insert_tile(game, game->img.background_frame,
			game->textures.wall_full, pos);
	else if (game->map.background_layer[y][x] == EMPTY_FLOOR)
		sl_insert_tile(game, game->img.background_frame,
			game->textures.floor, pos);
	else if (game->map.background_layer[y][x] == GRASS_FLOOR)
		sl_insert_tile(game, game->img.background_frame,
			game->textures.grass_floor, pos);
	else if (game->map.background_layer[y][x] == STEIN_FLOOR)
		sl_insert_tile(game, game->img.background_frame,
			game->textures.stein_floor, pos);
}

static void	draw_background(t_game *game)
{
	sl_tile_iterate(game, fill_background_tile);
}

void	sl_draw_background_frame(t_game *game)
{
	draw_background(game);
}
