/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:24:22 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/20 20:56:51 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

char	**sl_init_array(int height, int width)
{
	char	**res;
	int		i;

	res = (char **)ft_calloc(height, sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (i < height)
	{
		res[i] = ft_calloc(width, sizeof(char));
		if (!res[i])
		{
			sl_free_array_rows(res, i);
			return (NULL);
		}
		i++;
	}
	return (res);
}

char	**sl_copy_array(char **src, int height, int width)
{
	int		i;
	int		j;
	char	**res;

	if (!src)
		return (NULL);
	res = sl_init_array(height, width);
	if (!res)
		return (NULL);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			res[i][j] = src[i][j];
			j++;
		}
		i++;
	}
	return (res);
}
