/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:00:00 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/16 12:00:00 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	sl_free_grid(char **grid, int height)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	sl_free_map(t_map *map)
{
	if (!map)
		return ;
	sl_free_grid(map->grid, map->height);
	map->grid = NULL;
	map->height = 0;
	map->width = 0;
}

void	sl_free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->mlx && game->img.frame)
		mlx_delete_image(game->mlx, game->img.frame);
	if (game->mlx)
		mlx_terminate(game->mlx);
	sl_free_map(&game->map);
	game->mlx = NULL;
}
