/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:14:02 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/19 21:27:51 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static void anim(void *data)
{
	t_game *game;
	double now;
	
	game = (t_game *)data;
	now = mlx_get_time();
	if (now - game->last_frame_time < 0.08)
		return ;
	sl_redraw_animated(game);
	game->last_frame_time = now;
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
	mlx_loop_hook(game->mlx, anim, game);
	mlx_key_hook(game->mlx, sl_handle_key, game);
	mlx_close_hook(game->mlx, sl_close_hook, game);
	return (1);
}
