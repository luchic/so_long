#include "internal.h"

static int load_textures(t_game *game)
{
	game->textures.brazier.size = 6;
	game->textures.brazier.frames = ft_calloc(game->textures.brazier.size, sizeof(mlx_texture_t*));

	game->textures.brazier.frames[0] = mlx_load_png("./textures/brazier/brazier1.png");
	game->textures.brazier.frames[1] = mlx_load_png("./textures/brazier/brazier1.png");
	game->textures.brazier.frames[2] = mlx_load_png("./textures/brazier/brazier1.png");
	game->textures.brazier.frames[3] = mlx_load_png("./textures/brazier/brazier1.png");
	game->textures.brazier.frames[4] = mlx_load_png("./textures/brazier/brazier1.png");
	game->textures.brazier.frames[5] = mlx_load_png("./textures/brazier/brazier1.png");
	return (1);
}

int	sl_load_brazier_asset(t_game *game)
{
	if (!load_textures(game))
		return (0);
	return (1);
}
