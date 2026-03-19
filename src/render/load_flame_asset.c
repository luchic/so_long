#include "internal.h"

static int load_textures(t_game *game)
{
	game->textures.flame.size = 6;
	game->textures.flame.frames = ft_calloc(game->textures.flame.size, sizeof(mlx_texture_t*));

	game->textures.flame.frames[0] = mlx_load_png("./textures/flame/flame1.png");
	game->textures.flame.frames[1] = mlx_load_png("./textures/flame/flame2.png");
	game->textures.flame.frames[2] = mlx_load_png("./textures/flame/flame3.png");
	game->textures.flame.frames[3] = mlx_load_png("./textures/flame/flame4.png");
	game->textures.flame.frames[4] = mlx_load_png("./textures/flame/flame5.png");
	game->textures.flame.frames[5] = mlx_load_png("./textures/flame/flame6.png");
	return (1);
}

int	sl_load_flame_asset(t_game *game)
{
	if (!load_textures(game))
		return (0);
	return (1);
}
