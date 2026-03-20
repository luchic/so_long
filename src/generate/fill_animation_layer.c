#include "internal.h"

static int	is_corner(t_game *game, int y, int x)
{
	if ((y - 1) < 0 || (x - 1) < 0
		|| (x + 1) >= game->map.width || (y + 1) >= game->map.height)
	{
		return (0);
	}
	if (sl_iswall_tile(game->map.background_layer[y - 1][x])
		&& sl_iswall_tile(game->map.background_layer[y][x -1]))
		return (1);
	if (sl_iswall_tile(game->map.background_layer[y - 1][x])
		&& sl_iswall_tile(game->map.background_layer[y][x + 1]))
		return (1);
	if (sl_iswall_tile(game->map.background_layer[y + 1][x])
		&& sl_iswall_tile(game->map.background_layer[y][x - 1]))
		return (1);
	if (sl_iswall_tile(game->map.background_layer[y + 1][x])
		&& sl_iswall_tile(game->map.background_layer[y][x + 1]))
		return (1);
	return (0);
}

static int	is_interactive(t_game *game, int y, int x)
{
	if ((y - 1) < 0 || (x - 1) < 0
		|| (x + 1) >= game->map.width || (y + 1) >= game->map.height)
	{
		return (0);
	}
	if (sl_isplayer(game, y, x)
		|| sl_iscollectable(game->map.interactive_layer[y - 1][x]))
		return (1);
	if (sl_isplayer(game, y, x)
		|| sl_iscollectable(game->map.interactive_layer[y + 1][x]))
		return (1);
	if (sl_isplayer(game, y, x)
		|| sl_iscollectable(game->map.interactive_layer[y][x - 1]))
		return (1);
	if (sl_isplayer(game, y, x)
		|| sl_iscollectable(game->map.interactive_layer[y][x + 1]))
		return (1);
	return (0);
}

static void	generate_object(t_game *game, int y, int x)
{
	int	probobilty;

	if (game->map.animation_layer[y][x] == NONPLACEABLE)
		return ;
	probobilty = sl_random_range(0, 700);
	if (is_corner(game, y, x))
	{
		if (probobilty < 35)
			game->map.animation_layer[y][x] = BRAZIER;
		else if (probobilty < 50)
			game->map.animation_layer[y][x] = FLAME;
	}
	if (is_interactive(game, y, x))
	{
		if (probobilty < 5)
			game->map.animation_layer[y][x] = BRAZIER;
		else if (probobilty < 10)
			game->map.animation_layer[y][x] = FLAME;
	}
	if (probobilty < 10)
		game->map.animation_layer[y][x] = BRAZIER;
	else if (probobilty < 15)
		game->map.animation_layer[y][x] = FLAME;
}

static void	fill_animation_tile(t_game *game, int y, int x)
{
	if (sl_iswall_tile(game->map.background_layer[y][x])
		|| sl_isplayer(game, y, x)
		|| game->map.interactive_layer[y][x] == COLLECTABLE
		|| game->map.interactive_layer[y][x] == EXIT_CLOSED)
	{
		game->map.animation_layer[y][x] = NONPLACEABLE;
	}
	else
		game->map.animation_layer[y][x] = NONE;
	generate_object(game, y, x);
}

void	sl_fill_animation_layer(t_game *game)
{
	sl_tile_iterate(game, fill_animation_tile);
}
