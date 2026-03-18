/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_action_layer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:13:18 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/18 15:27:46 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	sl_redraw_acttion_layer(t_game *game)
{
	(void) game;
	return (1);
}

int	sl_init_action_frame(t_game *game)
{
	int	width;
	int	height;

	width = game->map.width * game->tile_size;
	height = game->map.height * game->tile_size;
	game->img.frame = mlx_new_image(game->mlx, width, height);
	if (!game->img.frame)
		return (0);
	if (mlx_image_to_window(game->mlx, game->img.frame, 0, 0) < 0)
		return (0);
	return (1);
}
