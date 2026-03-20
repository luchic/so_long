#include "internal.h"

void sl_render_animation_frame(void *data)
{
	t_game *game;
	double now;
	
	game = (t_game *)data;
	now = mlx_get_time();
	if (now - game->last_frame_time < 0.08)
		return ;
	sl_redraw_animated(game);
	game->last_frame_time = now;
}