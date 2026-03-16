/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:00:00 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/16 12:00:00 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static void	sl_dispatch_move(t_game *game, keys_t key)
{
	if (key == MLX_KEY_W || key == MLX_KEY_UP)
		sl_move_player(game, 0, -1);
	if (key == MLX_KEY_S || key == MLX_KEY_DOWN)
		sl_move_player(game, 0, 1);
	if (key == MLX_KEY_A || key == MLX_KEY_LEFT)
		sl_move_player(game, -1, 0);
	if (key == MLX_KEY_D || key == MLX_KEY_RIGHT)
		sl_move_player(game, 1, 0);
}

void	sl_handle_key(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		return (sl_close_game(game));
	if (game->game_over)
		return ;
	sl_dispatch_move(game, keydata.key);
}
