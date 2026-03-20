/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lose.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 21:00:35 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/20 21:00:37 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	sl_check_lose(t_game *game, int nx, int ny)
{
	if (game->map.interactive_layer[ny][nx] == FOE)
	{
		sl_close_game(game);
	}
}
