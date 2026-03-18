/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:14:10 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/18 10:21:39 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	sl_insert_tile(
	t_game *game,
	mlx_image_t *frame,
	mlx_image_t *tile,
	t_pos dpos)
{
	int			i;
	int			j;
	int			tile_size;
	uint32_t	*src;
	uint32_t	*dst;

	i = 0;
	tile_size = game->tile_size;
	src = (uint32_t *)tile->pixels;
	dst = (uint32_t *)frame->pixels;
	while (i < tile_size)
	{
		j = 0;
		while (j < tile_size)
		{
			dst[(tile_size * dpos.y + i) * (game->map.width * tile_size)
				+ (tile_size * dpos.x + j)] = src[i * tile_size + j];
			j++;
		}
		i++;
	}
	return (1);
}

static void	setup_background_tile(t_game *game, int y, int x)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	if (game->map.background_layer[y][x] == HORIZONTAL_WALL)
		sl_insert_tile(game, game->img.background_frame,
			game->img.wall_border, pos);
	else if (game->map.background_layer[y][x] == VERTICAL_WALL)
		sl_insert_tile(game, game->img.background_frame,
			game->img.wall_full, pos);
	else if (game->map.background_layer[y][x] == EMPRY_FLOOR)
		sl_insert_tile(game, game->img.background_frame, game->img.floor, pos);
	else if (game->map.background_layer[y][x] == GRASS_FLOOR)
		sl_insert_tile(game, game->img.background_frame,
			game->img.grass_floor, pos);
	else if (game->map.background_layer[y][x] == STEIN_FLOOR)
		sl_insert_tile(game, game->img.background_frame,
			game->img.stein_floor, pos);
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
	sl_generate_background(game);
	game->img.floor = mlx_texture_to_image(game->mlx, game->textures.floor);
	drow_background(game);
	mlx_image_to_window(game->mlx, game->img.background_frame, 0, 0);
	return (1);
}
