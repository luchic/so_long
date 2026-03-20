/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:25:03 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/20 16:29:55 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static void	update_tile(t_game *game, int y, int x)
{
	static unsigned long	iter = -1;
	t_pos					pos;

	if (y == 0 && x == 0)
		iter++;
	pos.x = x;
	pos.y = y;
	if (game->map.animation_layer[y][x] == FLAME)
	{
		sl_insert_tile(game, game->img.animation_frame,
			game->textures.flame.frames[iter % game->textures.flame.size], pos);
	}
	else if (game->map.animation_layer[y][x] == BRAZIER)
	{
		sl_insert_tile(game, game->img.animation_frame,
			game->textures.brazier.frames[iter % game->textures.brazier.size],
			pos);
	}
}

static void	animate(t_game *game)
{
	sl_tile_iterate(game, update_tile);
}

void	sl_redraw_animated(t_game *game)
{
	animate(game);
}
