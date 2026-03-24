/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:21:46 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/24 13:31:24 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	sl_render_animation_frame(t_game	*game)
{
	double	now;

	if (game->end_state != PLAYING)
	{
		sl_update_end_animation(game);
		return ;
	}
	now = mlx_get_time();
	if (now - game->last_frame_time < 0.08)
		return ;
	sl_redraw_animated(game);
	game->last_frame_time = now;
}
