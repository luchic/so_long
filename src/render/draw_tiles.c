#include "internal.h"

int	sl_insert_tile(
	t_game *game,
	mlx_image_t *frame,
	mlx_texture_t *tile,
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
