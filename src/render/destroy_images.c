/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:48:06 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/18 11:01:00 by nluchini         ###   ########.fr       */
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
	sl_free_texture(&(game->textures.collect_tex));
	sl_free_texture(&(game->textures.exit_tex));
	sl_free_texture(&(game->textures.player_tex));
}

void	sl_free_img(t_game *game, mlx_texture_t	**img)
{
	if (img || *img)
	{
		mlx_delete_image(game->mlx, *img);
		*img = NULL;
	}
}

void	sl_destroy_img(t_game *game)
{
	sl_free_img(game, &(game->img.wall_full));
	sl_free_img(game, &(game->img.wall_border));
	sl_free_img(game, &(game->img.floor));
	sl_free_img(game, &(game->img.grass_floor));
	sl_free_img(game, &(game->img.stein_floor));
	sl_free_img(game, &(game->img.collect_img));
	sl_free_img(game, &(game->img.exit_img));
	sl_free_img(game, &(game->img.player_img));
	sl_free_img(game, &(game->img.background_frame));
	sl_free_img(game, &(game->img.frame));
}
