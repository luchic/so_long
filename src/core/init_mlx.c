/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:14:02 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/24 13:41:42 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static void	loop_hook(void *data)
{
	t_game	*game;

	game = (t_game *)data;
	if (game->end_state == TOCLOSE)
	{
		sl_close_game(game);
	}
	sl_render_animation_frame(game);
}

int	sl_init_mlxwindow(t_game *game)
{
	int	width;
	int	height;

	width = game->map.width * game->tile_size;
	height = game->map.height * game->tile_size;
	game->mlx = mlx_init(width, height, SL_TITLE, true);
	if (!game->mlx)
	{
		return (0);
	}
	mlx_loop_hook(game->mlx, loop_hook, game);
	mlx_key_hook(game->mlx, sl_handle_key, game);
	mlx_close_hook(game->mlx, sl_close_hook, game);
	return (1);
}
