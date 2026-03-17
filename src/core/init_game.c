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

void	sl_init_player(t_game *game)
{
	game->player.pos = game->map.player_start;
	game->player.moves = 0;
	game->player.collected = 0;
	game->map.grid[game->player.pos.y][game->player.pos.x] = '0';
}

int sl_init_map(t_game *game, const char *path)
{
	if (!sl_parse_map(path, &game->map))
		return (0);
	if (!sl_validate_map(&game->map))
		return (sl_free_map(&game->map), 0);
	return (1);
}

int sl_init_mlxwindow(t_game *game)
{
	int width;
	int height;

	width = game->map.width * game->tile_size;
	height = game->map.height * game->tile_size;
	game->mlx = mlx_init(width, height, SL_TITLE, true);
	if (!game->mlx)
	{
		return (0);
	}
	if (!sl_render_init(game))
	{
		return (, 0);
	}
	mlx_key_hook(game->mlx, sl_handle_key, game);
	mlx_close_hook(game->mlx, sl_close_hook, game);
	return (0);
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
		sl_free_game(game)
		return (0);
	}
	sl_redraw(game);
	return (1);
}
