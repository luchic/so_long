/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_action_layer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:13:18 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/18 16:32:01 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	sl_redraw_acttion_layer(t_game *game)
{
	(void) game;
	return (1);
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
	if (layer[y][x] == PLAYER)
		sl_insert_tile(game, frame, game->textures.player, tile_position);
	else if (layer[y][x] == EXIT)
		sl_insert_tile(game, frame, game->textures.exit_close, tile_position);
	else if (layer[y][x] == COLLECTABLE)
		sl_insert_tile(game, frame, game->textures.collect, tile_position);
	else
		sl_insert_tile(game, frame, game->textures.empty, tile_position);
}

static void	draw_interactive_frame(t_game *game)
{
	sl_tile_iterate(game, draw_interactive_tile);
}

static int	init_interactive_frame(t_game *game)
{
	int	width;
	int	height;

	width = game->map.width * game->tile_size;
	height = game->map.height * game->tile_size;
	game->img.interactive_frame = mlx_new_image(game->mlx, width, height);
	if (!game->img.interactive_frame)
		return (0);
	if (mlx_image_to_window(game->mlx, game->img.interactive_frame, 0, 0) < 0)
		return (0);
	return (1);
}

int	sl_draw_interactive_frame(t_game *game)
{
	if (!init_interactive_frame(game))
		return (0);
	draw_interactive_frame(game);
	return (1);
}
