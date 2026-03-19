/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_interactive_layer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:13:34 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/19 11:17:33 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static void	set_interactive_tiles(t_game *game, int y, int x)
{
	if (game->map.grid[y][x] == 'C')
		game->map.interactive_layer[y][x] = COLLECTABLE;
	else if (game->map.grid[y][x] == 'E')
		game->map.interactive_layer[y][x] = EXIT_CLOSED;
}

void	sl_fill_interactive_layer(t_game *game)
{
	sl_tile_iterate(game, set_interactive_tiles);
}
