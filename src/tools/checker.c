#include "internal.h"

int	sl_iswall_tile(char tile)
{
	return (tile == HORIZONTAL_WALL || tile == VERTICAL_WALL);
}

int	sl_isplayer(t_game *game, int y, int x)
{	
	if (game->player.pos.y == y && game->player.pos.x == x)
		return (1);
	return (0);
}

int	sl_iscollectable(char tile)
{
	return (tile == COLLECTABLE);
}
