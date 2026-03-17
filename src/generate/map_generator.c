#include "internal.h"


int	sl_generate_background(t_game *game)
{
	sl_init_floor(game);
	sl_optimize_border_tiles(game);
	return (1);
}
