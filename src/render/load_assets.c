/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:00:00 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/16 12:00:00 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	sl_render_init(t_game *game)
{
	int	width;
	int	height;
	int	status;

	width = game->map.width * game->tile_size;
	height = game->map.height * game->tile_size;
	game->img.frame = mlx_new_image(game->mlx, width, height);
	if (!game->img.frame)
		return (0);
	status = mlx_image_to_window(game->mlx, game->img.frame, 0, 0);
	if (status < 0)
		return (0);
	return (1);
}
