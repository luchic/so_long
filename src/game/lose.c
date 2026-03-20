#include "internal.h"
#include <stdio.h>

void	sl_check_lose(t_game *game, int nx, int ny)
{
	if (game->map.interactive_layer[ny][nx] == FOE)
	{
		sl_close_game(game);
	}
}
