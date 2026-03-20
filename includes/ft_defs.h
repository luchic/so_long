/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_defs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:46:27 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/20 17:57:11 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEFS_H
# define FT_DEFS_H

# include "../mlx42/include/MLX42/MLX42.h"

typedef enum e_map_tile
{
	EMPTY,
	EMPTY_FLOOR,
	GRASS_FLOOR,
	STEIN_FLOOR,
	VERTICAL_WALL,
	HORIZONTAL_WALL,
	PLAYER,
	COLLECTABLE,
	EXIT_CLOSED,
	EXIT_OPEN,
	FOE,
}	t_map_tiles;

typedef enum e_animated
{
	NONPLACEABLE,
	NONE,
	FLAME,
	BRAZIER,
}	t_animated;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

// Map shouldn't contain informaiont about.
// background_layer / interactive_layer are declared as char **,
// but the code stores values from t_map_tiles (an enum).
// Using t_map_tiles ** (or a fixed-width integer type) will make
// the intent explicit and avoid surprises if the enum grows beyond char range.
typedef struct s_map
{
	char	**grid;
	char	**background_layer;
	char	**interactive_layer;
	char	**animation_layer;
	int		width;
	int		height;
	int		collectibles;
	int		exit_count;
	int		player_count;
	t_pos	player_start;
	t_pos	exit_pos;
}	t_map;

typedef struct s_player
{
	t_pos	pos;
	int		moves;
	int		collected;
}	t_player;

typedef struct s_animation
{
	int				size;
	mlx_texture_t	**frames;
}	t_animation;

typedef struct s_textures
{
	t_animation		flame;
	t_animation		brazier;
	mlx_texture_t	*wall_full;
	mlx_texture_t	*wall_border;
	mlx_texture_t	*floor;
	mlx_texture_t	*grass_floor;
	mlx_texture_t	*stein_floor;
	mlx_texture_t	*collect;
	mlx_texture_t	*exit_open;
	mlx_texture_t	*exit_close;
	mlx_texture_t	*player;
	mlx_texture_t	*empty;
}					t_textures;

typedef struct s_img
{
	mlx_image_t		*text;
	mlx_image_t		*background_frame;
	mlx_image_t		*interactive_frame;
	mlx_image_t		*animation_frame;
}					t_img;

typedef struct s_game
{
	mlx_t			*mlx;
	t_map			map;
	t_player		player;
	t_img			img;
	t_textures		textures;
	int				tile_size;
	int				game_over;
	double			last_frame_time;
}					t_game;

#endif