/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 00:00:00 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/24 12:40:13 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static uint32_t	end_color(t_end_state state, int alpha)
{
	if (state == WIN)
		return ((uint32_t)(24 << 24)
			| (uint32_t)(84 << 16)
			| (uint32_t)(28 << 8)
			| (uint32_t)alpha);
	return ((uint32_t)(70 << 24)
		| (uint32_t)(22 << 16)
		| (uint32_t)(22 << 8)
		| (uint32_t)alpha);
}

static void	center_text_image(mlx_image_t *img, int window_width, int y)
{
	if (!img || img->count == 0)
		return ;
	img->instances[0].x = (window_width - (int)img->width) / 2;
	img->instances[0].y = y;
}

static void	create_end_text(t_game *game, const char *title,
	const char *subtitle)
{
	int	width;
	int	height;
	int	title_y;
	int	subtitle_y;

	width = game->map.width * game->tile_size;
	height = game->map.height * game->tile_size;
	title_y = height / 2 - 36;
	subtitle_y = title_y + 46;
	game->img.end_title = mlx_put_string(game->mlx, (char *)title, 0, 0);
	game->img.end_subtitle = mlx_put_string(game->mlx, (char *)subtitle, 0, 0);
	center_text_image(game->img.end_title, width, title_y);
	center_text_image(game->img.end_subtitle, width, subtitle_y);
}

static int allocate_endframe(t_game *game)
{
	int	width;
	int	height;

	width = game->map.width * game->tile_size;
	height = game->map.height * game->tile_size;

	game->img.end_frame = mlx_new_image(game->mlx, width, height);
	if (!game->img.end_frame)
		return (0);
	if (mlx_image_to_window(game->mlx, game->img.end_frame, 0, 0) < 0)
		return (0);
	return (1);
}

static void	fill_end_frame(t_game *game, uint32_t color)
{
	mlx_image_t	*frame;
	int			width;
	int			height;

	frame = game->img.end_frame;
	width = game->map.width * game->tile_size;
	height = game->map.height * game->tile_size;
	sl_fill_frame(frame, height, width, color);
}

int	sl_start_end_animation(t_game *game, t_end_state state)
{
	if (!game || game->end_state != PLAYING)
		return (0);
	game->game_over = 1;
	game->end_state = state;
	game->end_started_at = mlx_get_time();

	if (!allocate_endframe(game))
		return (0);
	fill_end_frame(game, end_color(state, 118));
	if (state == WIN)
		create_end_text(game, "YOU WIN!", "Closing soon...");
	else
		create_end_text(game, "GAME OVER", "Closing soon...");
	return (1);
}

void	sl_update_end_animation(t_game *game)
{
	double	elapsed;

	if (!game || game->end_state == PLAYING)
		return ;
	elapsed = mlx_get_time() - game->end_started_at;
	if (elapsed >= game->end_duration)
	{
		sl_close_game(game);
		return ;
	}
}
