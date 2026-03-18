/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:00:00 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/16 12:00:00 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static void	sl_reset_game(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->tile_size = SL_TILE_SIZE;
}

static void	sl_init_player(t_game *game)
{
	game->player.pos = game->map.player_start;
	game->player.moves = 0;
	game->player.collected = 0;
	game->map.grid[game->player.pos.y][game->player.pos.x] = '0';
}

static int	sl_init_map(t_game *game, const char *path)
{
	if (!sl_parse_map(path, &game->map))
		return (0);
	if (!sl_validate_map(&game->map))
		return (sl_free_map(&game->map), 0);
	return (1);
}

int	sl_init_game(t_game *game, const char *path)
{
	sl_reset_game(game);
	if (!sl_init_map(game, path))
	{
		return (0);
	}
	sl_init_player(game);
	if (!sl_init_mlxwindow(game))
	{
		sl_free_game(game);
		return (0);
	}
	if (!sl_run_map_generation(game))
	{
		return (0);
	}
	if (!sl_render_init(game))
	{
		return (0);
	}
	return (1);
}
