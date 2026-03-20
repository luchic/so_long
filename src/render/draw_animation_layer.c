/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_animation_layer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:24:04 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/20 16:24:55 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static void	fill_animation_tile(t_game *game, int y, int x)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	if (game->map.animation_layer[y][x] == FLAME)
	{
		sl_insert_tile(game, game->img.animation_frame,
			game->textures.flame.frames[0], pos);
	}
	else if (game->map.animation_layer[y][x] == BRAZIER)
	{
		sl_insert_tile(game, game->img.animation_frame,
			game->textures.brazier.frames[0], pos);
	}
	else
	{
		sl_insert_tile(game, game->img.animation_frame,
			game->textures.empty, pos);
	}
}

static void	draw_animation_frame(t_game *game)
{
	sl_tile_iterate(game, fill_animation_tile);
}

void	sl_draw_animation_frame(t_game *game)
{
	draw_animation_frame(game);
}
