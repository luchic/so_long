/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_interactive_layer.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:13:16 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/20 21:01:01 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static void	clear_interactive_layer(t_game *game, int y, int x)
{
	game->map.interactive_layer[y][x] = EMPTY;
}

int	sl_alloc_interactive_layer(t_game *game)
{
	game->map.interactive_layer = sl_init_array(game->map.height,
			game->map.width);
	if (!game->map.interactive_layer)
		return (0);
	sl_tile_iterate(game, clear_interactive_layer);
	return (1);
}
