#include "internal.h"


static t_map_tiles get_random_floor_tile()
{
	int rand;

	rand = sl_random_range(1, 8);
	if (rand == 1)
		return (GRASS_FLOOR);
	if (rand == 2)
		return (STEIN_FLOOR);

	return (EMPRY_FLOOR);
}

int	sl_init_floor(t_game *game)
{
	int	i;
	int	j;

	game->map.background_layer = init_array(game->map.height, game->map.width);
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			game->map.background_layer[i][j] = get_random_floor_tile();
			j++;
		}
		i++;
	}
	return (1);
}
