#include "internal.h"

static int	is_horizontal_wall(t_game *game, int y, int x)
{
	char	**grid;

	if (y + 1 >= game->map.height)
		return (1);
	grid = game->map.grid;
	if (grid[y + 1][x] != '1')
		return (1);
	return (0);
}

static t_map_tiles	get_wall_tile(t_game *game, int y, int x)
{
	if (is_horizontal_wall(game, y, x))
		return (HORIZONTAL_WALL);
	return (VERTICAL_WALL);
}

static void	update_wall_tile(t_game *game, int y, int x)
{
	char	**grid;

	grid = game->map.grid;

	if (grid[y][x] == '1')
		game->map.background_layer[y][x] = get_wall_tile(game, y, x);
}

int	sl_optimize_border_tiles(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			update_wall_tile(game, i, j);
			j++;
		}
		i++;
	}
	return (1);
}
