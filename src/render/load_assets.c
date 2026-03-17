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

static int	init_textures(t_game *game)
{
	game->textures.wall_full = mlx_load_png("./textures/walls/wall.png");
	game->textures.wall_border = mlx_load_png("./textures/walls/Walls-5.png");
	game->textures.floor = mlx_load_png("./textures/floors/floor.png");
	game->textures.grass_floor = mlx_load_png("./textures/floors/grass_floor.png");
	game->textures.stein_floor = mlx_load_png("./textures/floors/stein_floor.png");
	return (1);
}

static int inti_images_on_textures(t_game *game)
{
	game->img.floor = mlx_texture_to_image(game->mlx, game->textures.floor);
	game->img.grass_floor = mlx_texture_to_image(game->mlx, game->textures.grass_floor);
	game->img.stein_floor = mlx_texture_to_image(game->mlx, game->textures.stein_floor);
	game->img.wall_full = mlx_texture_to_image(game->mlx, game->textures.wall_full);
	game->img.wall_border = mlx_texture_to_image(game->mlx, game->textures.wall_border);
	return (1);
}

int	sl_render_init(t_game *game)
{
	int	width;
	int	height;
	int	status;

	if (!init_textures(game))
		return (0);
	if (!inti_images_on_textures(game))
		return (0);
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
