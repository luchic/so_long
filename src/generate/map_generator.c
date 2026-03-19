/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:23:53 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/19 20:17:14 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	sl_generate_background(t_game *game)
{
	game->map.background_layer = init_array(game->map.height, game->map.width);
	if (!game->map.background_layer)
		return (0);
	sl_fill_floor_tiles(game);
	sl_fill_wall_tiles(game);
	return (1);
}

int	sl_run_map_generation(t_game *game)
{
	if (!sl_generate_background(game))
		return (0);
	if (!sl_generate_interactive_layer(game))
		return (0);
	if (!sl_generate_animation_layer(game))
		return (0);
	return (1);
}
