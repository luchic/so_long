/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:48:06 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/20 17:14:47 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	sl_free_animation_texture(t_animation *animation)
{
	int				i;
	mlx_texture_t	**frames;

	i = 0;
	frames = animation->frames;
	while (i < animation->size)
	{
		sl_free_texture(&(frames[i]));
		i++;
	}
	free(animation->frames);
	animation->frames = NULL;
	animation->size = 0;
}

void	sl_free_texture(mlx_texture_t	**texture)
{
	if (texture && *texture)
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
	sl_free_texture(&(game->textures.player));
	sl_free_texture(&(game->textures.empty));
	sl_free_texture(&(game->textures.exit_close));
	sl_free_texture(&(game->textures.exit_open));
	sl_free_animation_texture(&(game->textures.flame));
	sl_free_animation_texture(&(game->textures.brazier));
}

void	sl_free_img(t_game *game, mlx_image_t	**img)
{
	if (img && *img)
	{
		mlx_delete_image(game->mlx, *img);
		*img = NULL;
	}
}

void	sl_destroy_img(t_game *game)
{
	sl_free_img(game, &(game->img.background_frame));
	sl_free_img(game, &(game->img.interactive_frame));
	sl_free_img(game, &(game->img.animation_frame));
	sl_free_img(game, &(game->img.text));
}
