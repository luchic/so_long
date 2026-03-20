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

void	sl_free_map(t_map *map)
{
	if (!map)
		return ;
	sl_free_array_rows(map->grid, map->height);
	sl_free_array_rows(map->animation_layer, map->height);
	sl_free_array_rows(map->background_layer, map->height);
	sl_free_array_rows(map->interactive_layer, map->height);
	map->grid = NULL;
	map->height = 0;
	map->width = 0;
}

void	sl_free_game(t_game *game)
{
	if (!game)
		return ;
	sl_destroy_textures(game);
	if (game->mlx)
		sl_destroy_img(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	sl_free_map(&game->map);
	game->mlx = NULL;
}
