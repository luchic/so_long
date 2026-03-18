/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:24:04 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/18 11:57:36 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static t_map_tiles	get_random_floor_tile(void)
{
	int	rand;

	rand = sl_random_range(1, 8);
	if (rand == 1)
		return (GRASS_FLOOR);
	if (rand == 2)
		return (STEIN_FLOOR);
	return (EMPRY_FLOOR);
}

int	sl_init_floor(t_game *game)
{
	int	i;
	int	j;

	game->map.background_layer = init_array(game->map.height, game->map.width);
	if (!game->map.background_layer)
		return (0);
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			game->map.background_layer[i][j] = get_random_floor_tile();
			j++;
		}
		i++;
	}
	return (1);
}
