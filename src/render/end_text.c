/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:48:32 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/24 12:57:07 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static void	center_text_image(mlx_image_t *img, int window_width, int y)
{
	if (!img || img->count == 0)
		return ;
	img->instances[0].x = (window_width - (int)img->width) / 2;
	img->instances[0].y = y;
}

int	sl_create_end_text(t_game *game, const char *title,
	const char *subtitle)
{
	int	width;
	int	height;
	int	title_y;
	int	subtitle_y;

	game->img.end_title = mlx_put_string(game->mlx, (char *)title, 0, 0);
	game->img.end_subtitle = mlx_put_string(game->mlx, (char *)subtitle, 0, 0);
	if (!game->img.end_title || !game->img.end_subtitle)
	{
		sl_free_img(game, &(game->img.end_title));
		sl_free_img(game, &(game->img.end_subtitle));
		return (0);
	}
	width = game->map.width * game->tile_size;
	height = game->map.height * game->tile_size;
	title_y = height / 2 - 36;
	subtitle_y = title_y + 46;
	center_text_image(game->img.end_title, width, title_y);
	center_text_image(game->img.end_subtitle, width, subtitle_y);
	return (1);
}
