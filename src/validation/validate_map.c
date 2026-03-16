/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:00:00 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/16 12:00:00 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	sl_validate_map(t_map *map)
{
	if (!sl_validate_shape(map))
		return (sl_error("Invalid map shape"), 0);
	if (!sl_validate_chars(map))
		return (sl_error("Invalid map characters"), 0);
	if (!sl_validate_path(map))
		return (sl_error("Invalid map path"), 0);
	return (1);
}
