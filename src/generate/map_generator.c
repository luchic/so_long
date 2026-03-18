/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:23:53 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/18 11:57:48 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

// Add checking on null
int	sl_generate_background(t_game *game)
{
	sl_init_floor(game);
	sl_optimize_border_tiles(game);
	return (1);
}

void	sl_run_map_generation(t_game *game)
{
	sl_generate_background(game);
}
