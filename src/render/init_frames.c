/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frames.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:49:48 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/19 10:50:37 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	sl_init_background_frame(t_game *game)
{
	int	width;
	int	height;

	width = game->map.width * game->tile_size;
	height = game->map.height * game->tile_size;
	game->img.background_frame = mlx_new_image(game->mlx, width, height);
	if (!game->img.background_frame)
		return (0);
	if (mlx_image_to_window(game->mlx, game->img.background_frame, 0, 0) < 0)
		return (0);
	return (1);
}

int	sl_init_interactive_frame(t_game *game)
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
