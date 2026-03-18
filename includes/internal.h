/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:45:54 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/18 11:55:26 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "so_long.h"

int		sl_init_floor(t_game *game);
int		sl_optimize_border_tiles(t_game *game);
int		sl_init_backgournd(t_game *game);
int		sl_generate_background(t_game *game);
int		sl_random_range(int min, int max);

void	sl_free_texture(mlx_texture_t	**texture);
void	sl_destroy_textures(t_game *game);
void	sl_free_img(t_game *game, mlx_image_t	**img);
void	sl_destroy_img(t_game *game);

int		sl_load_assets(t_game *game);
int		sl_init_action_frame(t_game *game);

void	sl_run_map_generation(t_game *game);

char	**init_array(int height, int widht);
char	**copy_array(char **src, int height, int widht);
void	free_araay_rows(char **array, int size);
#endif
