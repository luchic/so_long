/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_moves_text.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 17:30:58 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/20 17:31:33 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static char	*get_string(int moves)
{
	char	*format;
	char	*number;
	char	*tmp;

	format = "Moves: ";
	number = ft_itoa(moves);
	if (!number)
		return (NULL);
	tmp = ft_strjoin(format, number);
	free(number);
	return (tmp);
}

void	sl_update_moves_text(t_game *game)
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
