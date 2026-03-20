/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:00:00 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/16 12:00:00 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

char	*get_string(int moves)
{
	char *format;
	char *tmp;
	char *nums;

	format = "Moves: ";
	nums = ft_itoa(moves);
	if (!nums)
		return (NULL);
	tmp = ft_strjoin(format, nums);
	free(nums);
	return (tmp);
}

void	put_string_to_screen(t_game *game)
{
	char		*printed_string;
	mlx_image_t	*img;

	printed_string = get_string(game->player.moves);
	if (!printed_string)
		return ;
	img = mlx_put_string(game->mlx, printed_string, 0, 0);
	free(printed_string);
	if (!img)
		return ;
	if (game->img.text)
		mlx_delete_image(game->mlx, game->img.text);
	game->img.text = img;
}

void	sl_move_player(t_game *game, int dx, int dy)
{
	int	nx;
	int	ny;

	nx = game->player.pos.x + dx;
	ny = game->player.pos.y + dy;
	if (!sl_can_move(game, nx, ny))
		return ;
	sl_try_collect(game, nx, ny);
	game->player.pos.x = nx;
	game->player.pos.y = ny;
	game->player.moves++;
	ft_printf("Moves: %d\n", game->player.moves);
	// mlx_put_string(game->mlx, "Moves: tmp", 0, 0);
	put_string_to_screen(game);
	sl_check_win(game, nx, ny);
	sl_redraw_interactive_frame(game);
}
