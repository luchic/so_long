#include "internal.h"

// y = y * height + x - simple (in sinne of tiles)
// But tiles has size (tile_size)
// i have dx, dy = tile position
// 


int	sl_insert_tile(
	t_game *game,
	mlx_image_t *frame,
	mlx_image_t *tile,
	t_pos dpos)
{
	int			i;
	int			j;
	int			tile_size;
	uint32_t	*src;
	uint32_t	*dst;

	i = 0;
	tile_size = game->tile_size;
	src = (uint32_t *)tile->pixels;
	dst = (uint32_t *)frame->pixels;

	while (i < tile_size)
	{
		j = 0;
		while (j < tile_size)
		{
			dst[(tile_size * dpos.y + i) * (game->map.width * tile_size)
				+ (tile_size * dpos.x + j)] = src[i * tile_size + j];
			j++;
		}
		i++;
	}
	return (1);
}


static int drow_background(t_game *game)
{
	int x = 0;
	int y = 0;
	t_pos pos;

	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			pos.x = x;
			pos.y = y;
			if (game->map.background_layer[y][x] == HORIZONTAL_WALL)
				sl_insert_tile(game, game->img.background_frame, game->img.wall_border, pos);
			else if (game->map.background_layer[y][x] == VERTICAL_WALL)
				sl_insert_tile(game, game->img.background_frame, game->img.wall_full, pos);
			else if (game->map.background_layer[y][x] == EMPRY_FLOOR)
				sl_insert_tile(game, game->img.background_frame, game->img.floor, pos);
			else if (game->map.background_layer[y][x] == GRASS_FLOOR)
				sl_insert_tile(game, game->img.background_frame, game->img.grass_floor, pos);
			else if (game->map.background_layer[y][x] == STEIN_FLOOR)
				sl_insert_tile(game, game->img.background_frame, game->img.stein_floor, pos);
			x++;
		}
		y++;
	}
	return (1);
}

int	sl_init_backgournd(t_game *game)
{
	int	width;
	int	height;

	sl_generate_background(game);

	width = game->map.width * game->tile_size;
	height = game->map.height * game->tile_size;
	game->img.floor = mlx_texture_to_image(game->mlx, game->textures.floor);
	drow_background(game);
	mlx_image_to_window(game->mlx, game->img.background_frame, 0, 0);
	return (1);
}