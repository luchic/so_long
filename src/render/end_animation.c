/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 00:00:00 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/24 13:25:34 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static int	allocate_endframe(t_game *game)
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

static int	start_end_animation(t_game *game, t_end_state state)
{
	if (!game || game->end_state != PLAYING)
		return (0);
	game->game_over = 1;
	game->end_state = state;
	game->end_started_at = mlx_get_time();
	if (!allocate_endframe(game))
		return (0);
	fill_end_frame(game, sl_end_color(state, 100));
	if (state == WIN)
		sl_create_end_text(game, "YOU WIN!", "Closing soon...");
	else
		sl_create_end_text(game, "GAME OVER", "Closing soon...");
	return (1);
}

int	sl_start_end_animation(t_game *game, t_end_state state)
{
	if (!start_end_animation(game, state))
	{
		game->end_state = TOCLOSE;
		return (0);
	}
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
