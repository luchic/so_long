/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:00:00 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/16 12:00:00 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		sl_error("Usage: ./so_long <map.ber>");
		return (1);
	}
	if (!sl_init_game(&game, argv[1]))
		return (1);
	mlx_loop(game.mlx);
	sl_free_game(&game);
	return (0);
}
