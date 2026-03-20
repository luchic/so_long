/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:00:00 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/16 12:00:00 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	sl_move_player(t_game *game, int dx, int dy)
{
	int	nx;
	int	ny;

	nx = game->player.pos.x + dx;
	ny = game->player.pos.y + dy;
	if (!sl_can_move(game, nx, ny))
		return ;
	sl_try_collect(game, nx, ny);
	game->player.pos.x = nx;
	game->player.pos.y = ny;
	game->player.moves++;
	ft_printf("Moves: %d\n", game->player.moves);
	sl_update_moves_text(game);
	sl_check_win(game, nx, ny);
	sl_redraw_interactive_frame(game);
}
