#include "internal.h"

static void	clear_animation_layer(t_game *game, int y, int x)
{
	game->map.animation_layer[y][x] = NONE;
}

int	sl_alloc_animation_layer(t_game *game)
{
	game->map.animation_layer = init_array(game->map.height, game->map.width);
	if (!game->map.animation_layer)
		return (0);
	sl_tile_iterate(game, clear_animation_layer);
	return (1);
}
