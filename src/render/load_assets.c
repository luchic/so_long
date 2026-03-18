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
	game->textures.grass_floor = mlx_load_png(
			"./textures/floors/grass_floor.png");
	game->textures.stein_floor = mlx_load_png(
			"./textures/floors/stein_floor.png");
	if (!game->textures.wall_full
		|| !game->textures.wall_border
		|| !game->textures.floor
		|| !game->textures.grass_floor
		|| !game->textures.stein_floor)
	{
		sl_destroy_textures(game);
		return (0);
	}
	return (1);
}

static int	init_images_on_textures(t_game *game)
{
	game->img.floor = mlx_texture_to_image(game->mlx, game->textures.floor);
	game->img.grass_floor = mlx_texture_to_image(game->mlx,
			game->textures.grass_floor);
	game->img.stein_floor = mlx_texture_to_image(game->mlx,
			game->textures.stein_floor);
	game->img.wall_full = mlx_texture_to_image(game->mlx,
			game->textures.wall_full);
	game->img.wall_border = mlx_texture_to_image(game->mlx,
			game->textures.wall_border);
	if (!game->img.floor
		|| !game->img.grass_floor
		|| !game->img.stein_floor
		|| !game->img.wall_full
		|| !game->img.wall_border)
	{
		sl_destroy_img(game);
		return (0);
	}
	return (1);
}

int	sl_load_assets(t_game *game)
{
	if (!init_textures(game))
		return (0);
	if (!init_images_on_textures(game))
	{
		sl_destroy_textures(game);
		return (0);
	}
	return (1);
}
