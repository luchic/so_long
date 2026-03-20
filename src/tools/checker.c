/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:26:42 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/20 16:29:25 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	sl_iswall_tile(char tile)
{
	return (tile == HORIZONTAL_WALL || tile == VERTICAL_WALL);
}

int	sl_isplayer(t_game *game, int y, int x)
{
	if (game->player.pos.y == y && game->player.pos.x == x)
		return (1);
	return (0);
}

int	sl_iscollectable(char tile)
{
	return (tile == COLLECTABLE);
}
