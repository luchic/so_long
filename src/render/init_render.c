/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:44:41 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/19 10:57:44 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	sl_render_init(t_game *game)
{
	if (!sl_load_assets(game))
	{
		return (0);
	}
	if (!sl_init_background_frame(game))
	{
		return (0);
	}
	if (!sl_init_interactive_frame(game))
	{
		return (0);
	}
	sl_draw_background_frame(game);
	sl_draw_interactive_frame(game);
	return (1);
}
