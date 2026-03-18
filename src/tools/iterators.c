#include "internal.h"

void	sl_tile_iterate(t_game *game, void (*f)(t_game*, int, int))
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			f(game, i, j);
			j++;
		}
		i++;
	}
}
