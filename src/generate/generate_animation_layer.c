/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_animation_layer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:26:28 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/20 16:26:33 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	sl_generate_animation_layer(t_game *game)
{
	if (!sl_alloc_animation_layer(game))
		return (0);
	sl_fill_animation_layer(game);
	return (1);
}
