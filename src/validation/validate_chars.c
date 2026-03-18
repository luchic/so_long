/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:00:00 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/16 12:00:00 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static int	sl_is_valid_cell(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

static void	sl_track_cell(t_map *map, char c, int x, int y)
{
	if (c == 'C')
		map->collectibles++;
	if (c == 'E')
	{
		map->exit_count++;
		map->exit_pos.x = x;
		map->exit_pos.y = y;
	}
	if (c == 'P')
	{
		map->player_count++;
		map->player_start.x = x;
		map->player_start.y = y;
	}
}

int	sl_validate_chars(t_map *map)
{
	int		y;
	int		x;
	char	cell;

	map->collectibles = 0;
	map->exit_count = 0;
	map->player_count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			cell = map->grid[y][x];
			if (!sl_is_valid_cell(cell))
				return (0);
			sl_track_cell(map, cell, x, y);
			x++;
		}
		y++;
	}
	if ((map->exit_count != 1 || map->player_count != 1)
		|| map->collectibles < 1)
		return (0);
	return (1);
}
