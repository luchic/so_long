#include "internal.h"

int	sl_generate_animation_layer(t_game *game)
{
	if (!sl_alloc_animation_layer(game))
		return (0);

	sl_fill_animation_layer(game);
	return (1);
}