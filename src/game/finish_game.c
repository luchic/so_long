/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:00:00 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/24 12:16:25 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	sl_check_win(t_game *game, int nx, int ny)
{
	if (game->map.interactive_layer[ny][nx] != EXIT_OPEN)
		return ;
	if (game->player.collected != game->map.collectibles)
		return ;
	sl_start_end_animation(game, WIN);
}

void	sl_check_lose(t_game *game, int nx, int ny)
{
	if (game->map.interactive_layer[ny][nx] == FOE)
	{
		sl_start_end_animation(game, LOSE);
	}
}
