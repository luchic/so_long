/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:00:00 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/16 12:00:00 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static int	sl_in_bounds(int x, int y, int width, int height)
{
	return (x >= 0 && y >= 0 && x < width && y < height);
}

void	sl_flood_fill(char **grid, int width, int height, t_pos start)
{
	int	x;
	int	y;

	x = start.x;
	y = start.y;
	if (!sl_in_bounds(x, y, width, height))
		return ;
	if (grid[y][x] == '1' || grid[y][x] == 'V' || grid[y][x] == 'O')
		return ;
	if (grid[y][x] == 'E')
	{
		grid[y][x] = 'O';
		return ;
	}
	grid[y][x] = 'V';
	sl_flood_fill(grid, width, height, (t_pos){x + 1, y});
	sl_flood_fill(grid, width, height, (t_pos){x - 1, y});
	sl_flood_fill(grid, width, height, (t_pos){x, y + 1});
	sl_flood_fill(grid, width, height, (t_pos){x, y - 1});
}
