/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:14:10 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/18 12:30:47 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static void	setup_background_tile(t_game *game, int y, int x)
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

static int	drow_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			setup_background_tile(game, y, x);
			x++;
		}
		y++;
	}
	return (1);
}

int	sl_init_backgournd(t_game *game)
{
	int	width;
	int	height;

	width = game->map.width * game->tile_size;
	height = game->map.height * game->tile_size;
	game->img.background_frame = mlx_new_image(game->mlx, width, height);
	if (!game->img.background_frame)
		return (0);
	drow_background(game);
	if (mlx_image_to_window(game->mlx, game->img.background_frame, 0, 0) < 0)
		return (0);
	return (1);
}
