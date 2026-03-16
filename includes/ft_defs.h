/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_defs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:46:27 by nluchini          #+#    #+#             */
/*   Updated: 2025/09/28 22:01:08 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEFS_H
# define FT_DEFS_H

# include "../mlx42/include/MLX42/MLX42.h"

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	char	**grid;
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

typedef struct s_img
{
	mlx_texture_t	*wall_tex;
	mlx_texture_t	*floor_tex;
	mlx_texture_t	*collect_tex;
	mlx_texture_t	*exit_tex;
	mlx_texture_t	*player_tex;
	mlx_image_t		*frame;
}	t_img;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		map;
	t_player	player;
	t_img		img;
	int			tile_size;
	int			game_over;
}	t_game;

#endif