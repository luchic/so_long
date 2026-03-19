#include "internal.h"

static void	replase_clased_door(t_game *game, int y, int x)
{
	if (game->map.interactive_layer[y][x] == EXIT_CLOSED)
	{
		game->map.interactive_layer[y][x] = EXIT_OPEN;
	}
}

static void	setup_open_door(t_game *game)
{
	sl_tile_iterate(game, replase_clased_door);
}

void	sl_try_collect(t_game *game, int nx, int ny)
{
	if (game->map.interactive_layer[ny][nx] == COLLECTABLE)
	{
		game->player.collected++;
		game->map.interactive_layer[ny][nx] = EMPTY;
		if (game->player.collected == game->map.collectibles)
			setup_open_door(game);
	}
}
