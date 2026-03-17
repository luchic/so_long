/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:45:54 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/17 20:32:47 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "so_long.h"

int sl_init_floor(t_game *game);
int sl_optimize_border_tiles(t_game *game);
int	sl_init_backgournd(t_game *game);
int	sl_generate_background(t_game *game);
int	sl_random_range(int min, int max);


char	**init_array(int height, int widht);
char	**copy_array(char **src, int height, int widht);
#endif
