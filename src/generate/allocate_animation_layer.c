/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_animation_layer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:26:38 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/20 21:00:54 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static void	clear_animation_layer(t_game *game, int y, int x)
{
	game->map.animation_layer[y][x] = NONE;
}

int	sl_alloc_animation_layer(t_game *game)
{
	game->map.animation_layer = sl_init_array(game->map.height,
			game->map.width);
	if (!game->map.animation_layer)
		return (0);
	sl_tile_iterate(game, clear_animation_layer);
	return (1);
}
