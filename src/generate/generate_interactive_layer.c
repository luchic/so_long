/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_interactive_layer.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:25:10 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/18 15:29:59 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	sl_generate_interactive_layer(t_game *game)
{
	if (!sl_alloc_interactive_layer(game))
	{
		return (0);
	}
	sl_fill_interactive_layer(game);
	return (1);
}
