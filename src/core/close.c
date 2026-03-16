/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:00:00 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/16 12:00:00 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	sl_close_game(t_game *game)
{
	if (!game || game->game_over)
		return ;
	game->game_over = 1;
	mlx_close_window(game->mlx);
}

void	sl_close_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	sl_close_game(game);
}
