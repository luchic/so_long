/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:45:54 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/20 18:19:05 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "so_long.h"

// ====================== Game ==============================
void	sl_check_lose(t_game *game, int nx, int ny);

// ================== Old =============
int		sl_generate_background(t_game *game);
int		sl_random_range(int min, int max);

void	sl_free_texture(mlx_texture_t	**texture);
void	sl_destroy_textures(t_game *game);
void	sl_free_img(t_game *game, mlx_image_t	**img);
void	sl_destroy_img(t_game *game);

int		sl_load_assets(t_game *game);

int		sl_run_map_generation(t_game *game);

char	**init_array(int height, int widht);
char	**copy_array(char **src, int height, int widht);
void	free_araay_rows(char **array, int size);

int		sl_insert_tile(t_game *game, mlx_image_t *interactive_frame,
			mlx_texture_t *tile, t_pos dpos);

// ====================== Render ============================
void	sl_draw_animation_frame(t_game *game);
void	sl_draw_background_frame(t_game *game);
void	sl_draw_interactive_frame(t_game *game);
int		sl_init_background_frame(t_game *game);
int		sl_init_interactive_frame(t_game *game);
int		sl_init_animation_frame(t_game *game);
void	sl_redraw_interactive_frame(t_game *game);

int		sl_load_brazier_asset(t_game *game);
int		sl_load_flame_asset(t_game *game);

void	sl_redraw_animated(t_game *game);

void	sl_render_animation_frame(void *data);

void	sl_update_moves_text(t_game *game);

// =================== Map generation =======================
int		sl_generate_interactive_layer(t_game *game);
int		sl_alloc_interactive_layer(t_game *game);
void	sl_tile_iterate(t_game *game, void (*f)(t_game*, int, int));
void	sl_fill_interactive_layer(t_game *game);
void	sl_fill_floor_tiles(t_game *game);
void	sl_fill_wall_tiles(t_game *game);

void	sl_fill_animation_layer(t_game *game);
int		sl_generate_animation_layer(t_game *game);
int		sl_alloc_animation_layer(t_game *game);
int		sl_iswall_tile(char tile);
int		sl_isplayer(t_game *game, int y, int x);
int		sl_iscollectable(char tile);
#endif
