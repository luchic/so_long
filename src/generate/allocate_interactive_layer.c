#include "internal.h"

static void	clear_interactive_layer(t_game *game, int y, int x)
{
	game->map.interactive_layer[y][x] = EMPTY;
}

int	sl_alloc_interactive_layer(t_game *game)
{
	game->map.interactive_layer = init_array(game->map.height, game->map.width);
	if (!game->map.interactive_layer)
		return (0);
	sl_tile_iterate(game, clear_interactive_layer);
	return (1);
}
