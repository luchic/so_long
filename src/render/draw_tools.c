/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:13:12 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/24 11:58:09 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	sl_fill_frame(mlx_image_t *frame, int height, int width, uint32_t color)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			mlx_put_pixel(frame, x, y, color);
			x++;
		}
		y++;
	}
}

int	sl_insert_tile(
	t_game *game,
	mlx_image_t *interactive_frame,
	mlx_texture_t *tile,
	t_pos dpos)
{
	int			i;
	int			j;
	int			tile_size;
	uint32_t	*src;
	uint32_t	*dst;

	i = 0;
	tile_size = game->tile_size;
	src = (uint32_t *)tile->pixels;
	dst = (uint32_t *)interactive_frame->pixels;
	while (i < tile_size)
	{
		j = 0;
		while (j < tile_size)
		{
			dst[(tile_size * dpos.y + i) * (game->map.width * tile_size)
				+ (tile_size * dpos.x + j)] = src[i * tile_size + j];
			j++;
		}
		i++;
	}
	return (1);
}
