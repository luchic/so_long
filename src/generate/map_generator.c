/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:23:53 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/18 12:00:06 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	sl_generate_background(t_game *game)
{
	if (!sl_init_floor(game))
		return (0);
	sl_optimize_border_tiles(game);
	return (1);
}

int	sl_run_map_generation(t_game *game)
{
	if (!sl_generate_background(game))
		return (0);
	return (1);
}
