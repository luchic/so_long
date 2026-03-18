/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:44:41 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/18 11:36:42 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	sl_render_init(t_game *game)
{
	if (!sl_load_assets(game))
		return (0);
	if (!sl_init_backgournd(game))
		return (0);
	if (!sl_init_action_frame(game))
		return (0);
	return (1);
}
