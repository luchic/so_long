/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_shape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:00:00 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/16 12:00:00 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static int	sl_row_all_walls(const char *row, int width)
{
	int	x;

	x = 0;
	while (x < width)
	{
		if (row[x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	sl_validate_shape(t_map *map)
{
	int	y;
	int	len;

	if (!map->grid || map->height <= 0)
		return (0);
	map->width = ft_strlen(map->grid[0]);
	if (map->width <= 0)
		return (0);
	y = 0;
	while (y < map->height)
	{
		len = ft_strlen(map->grid[y]);
		if (len != map->width)
			return (0);
		if (map->grid[y][0] != '1'
			|| map->grid[y][map->width - 1] != '1')
			return (0);
		y++;
	}
	if (!sl_row_all_walls(map->grid[0], map->width))
		return (0);
	if (!sl_row_all_walls(map->grid[map->height - 1], map->width))
		return (0);
	return (1);
}
