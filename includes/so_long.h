/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:00:00 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/16 12:00:00 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_defs.h"
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define SL_TILE_SIZE 32
# define SL_TITLE "so_long"

char	*get_next_line(int fd);

void	sl_error(const char *msg);
void	sl_free_map(t_map *map);
void	sl_free_game(t_game *game);
void	sl_close_game(t_game *game);
void	sl_close_hook(void *param);
int		sl_init_game(t_game *game, const char *path);

int		sl_parse_map(const char *path, t_map *map);
int		sl_read_map(const char *path, t_map *map);
char	*sl_strip_newline(char *line);
char	**sl_grow_grid(char **grid, int old_cap, int new_cap);
int		sl_has_extension(const char *path, const char *ext);

int		sl_validate_map(t_map *map);
int		sl_validate_shape(t_map *map);
int		sl_validate_chars(t_map *map);
int		sl_validate_path(t_map *map);
void	sl_flood_fill(char **grid, int width, int height, t_pos start);
char	**sl_dup_grid(char **grid, int height);

int		sl_render_init(t_game *game);
void	sl_draw_map(t_game *game);
void	sl_redraw(t_game *game);

void	sl_handle_key(mlx_key_data_t keydata, void *param);
void	sl_move_player(t_game *game, int dx, int dy);
int		sl_can_move(t_game *game, int nx, int ny);
void	sl_try_collect(t_game *game, int nx, int ny);
void	sl_check_win(t_game *game, int nx, int ny);

int		sl_init_mlxwindow(t_game *game);
#endif
