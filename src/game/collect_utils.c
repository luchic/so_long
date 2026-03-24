/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:07:27 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/20 20:57:38 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static void	replace_closed_door(t_game *game, int y, int x)
{
	if (game->map.interactive_layer[y][x] == EXIT_CLOSED)
	{
		game->map.interactive_layer[y][x] = EXIT_OPEN;
	}
}

static void	setup_open_door(t_game *game)
{
	sl_tile_iterate(game, replace_closed_door);
}

void	sl_try_collect(t_game *game, int nx, int ny)
{
	if (game->map.interactive_layer[ny][nx] == COLLECTABLE)
	{
		game->player.collected++;
		game->map.interactive_layer[ny][nx] = EMPTY;
		if (game->player.collected == game->map.collectibles)
			setup_open_door(game);
	}
}
