/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_interactive_layer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:13:18 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/19 11:11:02 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static void	draw_player_tile(t_game *game)
{
	sl_insert_tile(game, game->img.interactive_frame,
		game->textures.player, game->player.pos);
}

static void	draw_interactive_tile(t_game *game, int y, int x)
{
	char		**layer;
	t_pos		tile_position;
	mlx_image_t	*frame;

	frame = game->img.interactive_frame;
	layer = game->map.interactive_layer;
	tile_position.x = x;
	tile_position.y = y;
	if (layer[y][x] == EXIT)
		sl_insert_tile(game, frame, game->textures.exit_close, tile_position);
	else if (layer[y][x] == EXIT_OPEN)
		sl_insert_tile(game, frame, game->textures.exit_open, tile_position);
	else if (layer[y][x] == COLLECTABLE)
		sl_insert_tile(game, frame, game->textures.collect, tile_position);
	else
		sl_insert_tile(game, frame, game->textures.empty, tile_position);
}

static void	draw_interactive_frame(t_game *game)
{
	sl_tile_iterate(game, draw_interactive_tile);
	draw_player_tile(game);
}

void	sl_draw_interactive_frame(t_game *game)
{
	draw_interactive_frame(game);
}
