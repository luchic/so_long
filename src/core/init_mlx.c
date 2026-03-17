#include "internal.h"

int	sl_init_mlxwindow(t_game *game)
{
	int	width;
	int	height;

	width = game->map.width * game->tile_size;
	height = game->map.height * game->tile_size;
	game->mlx = mlx_init(width, height, SL_TITLE, true);
	if (!game->mlx)
	{
		return (0);
	}
	if (!sl_render_init(game))
	{
		return (0);
	}
	mlx_key_hook(game->mlx, sl_handle_key, game);
	mlx_close_hook(game->mlx, sl_close_hook, game);
	return (1);
}