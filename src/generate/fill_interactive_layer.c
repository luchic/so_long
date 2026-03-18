#include "internal.h"

static void	set_interatvie_tiles(t_game *game, int y, int x)
{
	if (game->map.grid[y][x] == 'C')
		game->map.interactive_layer[y][x] = COLLECTABLE;
	else if (game->map.grid[y][x] == 'E')
		game->map.interactive_layer[y][x] = EXIT;
}

void	sl_fill_interactive_layer(t_game *game)
{
	sl_tile_iterate(game, set_interatvie_tiles);
}
