/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:00:00 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/16 12:00:00 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static uint32_t	sl_cell_color(char cell)
{
	if (cell == '1')
		return (0x2D2D2DFF);
	if (cell == 'C')
		return (0xE5C07BFF);
	if (cell == 'E')
		return (0x98C379FF);
	return (0x3C3F41FF);
}

static void	sl_draw_rect(mlx_image_t *img, t_pos pixel_position, int size,
		uint32_t color)
{
	int	dx;
	int	dy;

	dy = 0;
	while (dy < size)
	{
		dx = 0;
		while (dx < size)
		{
			mlx_put_pixel(img, pixel_position.x + dx,
				pixel_position.y + dy, color);
			dx++;
		}
		dy++;
	}
}

static void	sl_draw_cell(t_game *game, int x, int y, uint32_t color)
{
	t_pos	pixel_position;
	int		px;
	int		py;

	px = x * game->tile_size;
	py = y * game->tile_size;
	pixel_position.x = px;
	pixel_position.y = py;
	sl_draw_rect(game->img.interactive_frame, pixel_position, game->tile_size, color);
}

void	sl_draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			sl_draw_cell(game, x, y, sl_cell_color(game->map.grid[y][x]));
			x++;
		}
		y++;
	}
	sl_draw_cell(game, game->player.pos.x, game->player.pos.y, 0x61AFEFFF);
}
