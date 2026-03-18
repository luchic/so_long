/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:48:06 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/18 15:47:32 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	sl_free_texture(mlx_texture_t	**texture)
{
	if (texture || *texture)
	{
		mlx_delete_texture(*texture);
		*texture = NULL;
	}
}

void	sl_destroy_textures(t_game *game)
{
	sl_free_texture(&(game->textures.wall_full));
	sl_free_texture(&(game->textures.wall_border));
	sl_free_texture(&(game->textures.floor));
	sl_free_texture(&(game->textures.grass_floor));
	sl_free_texture(&(game->textures.stein_floor));
	sl_free_texture(&(game->textures.collect));
	sl_free_texture(&(game->textures.exit));
	sl_free_texture(&(game->textures.player));
	sl_free_texture(&(game->textures.empty));
}

void	sl_free_img(t_game *game, mlx_image_t	**img)
{
	if (img || *img)
	{
		mlx_delete_image(game->mlx, *img);
		*img = NULL;
	}
}

void	sl_destroy_img(t_game *game)
{
	sl_free_img(game, &(game->img.background_frame));
	sl_free_img(game, &(game->img.frame));
}
