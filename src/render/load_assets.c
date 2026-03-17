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

int sl_init_textures(t_game *game)
{
	game->textures.wall_tex = mlx_load_png("./textures/wall.png");
	game->textures.floor_tex = mlx_load_png("./textures/floor.png");
	return 1;
}

int	sl_render_init(t_game *game)
{
	int	width;
	int	height;
	int	status;

	if (!sl_init_textures(game))
		return (0;)
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
