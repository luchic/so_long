/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:00:00 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/16 12:00:00 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

char	**sl_dup_grid(char **grid, int height)
{
	char	**copy;
	int		i;

	copy = ft_calloc(height + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(grid[i]);
		if (!copy[i])
			return (free_araay_rows(copy, i), NULL);
		i++;
	}
	return (copy);
}

static int	sl_has_unreached(char **grid, int width, int height)
{
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (grid[y][x] == 'C' || grid[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	sl_validate_path(t_map *map)
{
	char	**copy;

	copy = sl_dup_grid(map->grid, map->height);
	if (!copy)
		return (0);
	sl_flood_fill(copy, map->width, map->height, map->player_start);
	if (sl_has_unreached(copy, map->width, map->height))
		return (free_araay_rows(copy, map->height), 0);
	free_araay_rows(copy, map->height);
	return (1);
}
