/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_brazier_asset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:23:31 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/20 16:23:39 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static int	load_textures(t_game *game)
{
	game->textures.brazier.size = 6;
	game->textures.brazier.frames = ft_calloc(game->textures.brazier.size,
			sizeof(mlx_texture_t*));
	game->textures.brazier.frames[0] = mlx_load_png(
			"./textures/brazier/brazier1.png");
	game->textures.brazier.frames[1] = mlx_load_png(
			"./textures/brazier/brazier2.png");
	game->textures.brazier.frames[2] = mlx_load_png(
			"./textures/brazier/brazier3.png");
	game->textures.brazier.frames[3] = mlx_load_png(
			"./textures/brazier/brazier4.png");
	game->textures.brazier.frames[4] = mlx_load_png(
			"./textures/brazier/brazier5.png");
	game->textures.brazier.frames[5] = mlx_load_png(
			"./textures/brazier/brazier6.png");
	return (1);
}

int	sl_load_brazier_asset(t_game *game)
{
	if (!load_textures(game))
		return (0);
	return (1);
}
