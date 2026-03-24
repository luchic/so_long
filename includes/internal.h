/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:45:54 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/24 15:24:00 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "ft_defs.h"
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define SL_TILE_SIZE 32
# define SL_TITLE "so_long"

char		*get_next_line(int fd);

// ====================== Core ==============================
void		sl_error(const char *msg);
void		sl_free_map(t_map *map);
void		sl_free_game(t_game *game);
void		sl_close_game(t_game *game);
void		sl_close_hook(void *param);
void		sl_free_texture(mlx_texture_t **texture);
void		sl_destroy_textures(t_game *game);
void		sl_free_img(t_game *game, mlx_image_t **img);
void		sl_destroy_img(t_game *game);
int			sl_init_game(t_game *game, const char *path);
int			sl_init_mlxwindow(t_game *game);

// ===================== Parsing ============================
int			sl_parse_map(const char *path, t_map *map);
int			sl_read_map(const char *path, t_map *map);
char		*sl_strip_newline(char *line);
char		**sl_grow_grid(char **grid, int old_cap, int new_cap);
int			sl_has_extension(const char *path, const char *ext);

// ==================== Validation ==========================
int			sl_validate_map(t_map *map);
int			sl_validate_shape(t_map *map);
int			sl_validate_chars(t_map *map);
int			sl_validate_path(t_map *map);
void		sl_flood_fill(char **grid, int width, int height, t_pos start);

// ====================== Game ==============================
void		sl_handle_key(mlx_key_data_t keydata, void *param);
void		sl_move_player(t_game *game, int dx, int dy);
int			sl_can_move(t_game *game, int nx, int ny);
void		sl_try_collect(t_game *game, int nx, int ny);
void		sl_check_win(t_game *game, int nx, int ny);
void		sl_check_lose(t_game *game, int nx, int ny);
int			sl_start_end_animation(t_game *game, t_end_state state);
void		sl_update_end_animation(t_game *game);

// ====================== Render ============================
int			sl_render_init(t_game *game);
int			sl_load_assets(t_game *game);
int			sl_load_brazier_asset(t_game *game);
int			sl_load_flame_asset(t_game *game);
void		sl_draw_map(t_game *game);
void		sl_redraw(t_game *game);
void		sl_draw_animation_frame(t_game *game);
void		sl_draw_background_frame(t_game *game);
void		sl_draw_interactive_frame(t_game *game);
void		sl_redraw_interactive_frame(t_game *game);
void		sl_redraw_animated(t_game *game);
void		sl_render_animation_frame(t_game *game);
int			sl_init_background_frame(t_game *game);
int			sl_init_interactive_frame(t_game *game);
int			sl_init_animation_frame(t_game *game);
int			sl_insert_tile(t_game *game, mlx_image_t *interactive_frame,
				mlx_texture_t *tile, t_pos dpos);
void		sl_update_moves_text(t_game *game);
void		sl_fill_frame(mlx_image_t *frame, int height, int width,
				uint32_t color);
uint32_t	sl_end_color(t_end_state state, int alpha);
int			sl_create_end_text(t_game *game, const char *title,
				const char *subtitle);

// =================== Map generation =======================
int			sl_run_map_generation(t_game *game);
int			sl_generate_interactive_layer(t_game *game);
int			sl_alloc_interactive_layer(t_game *game);
void		sl_fill_interactive_layer(t_game *game);
void		sl_fill_floor_tiles(t_game *game);
void		sl_fill_wall_tiles(t_game *game);
int			sl_generate_animation_layer(t_game *game);
int			sl_alloc_animation_layer(t_game *game);
void		sl_fill_animation_layer(t_game *game);
void		sl_tile_iterate(t_game *game, void (*f)(t_game *, int, int));
int			sl_iswall_tile(char tile);
int			sl_isplayer(t_game *game, int y, int x);
int			sl_iscollectable(char tile);

// ====================== Utils =============================
int			sl_random_range(int min, int max);
char		**sl_init_array(int height, int width);
char		**sl_copy_array(char **src, int height, int width);
void		sl_free_array_rows(char **array, int size);

#endif
