/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:00:00 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/16 12:00:00 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	sl_has_extension(const char *path, const char *ext)
{
	size_t	len_path;
	size_t	len_ext;

	if (!path || !ext)
		return (0);
	len_path = ft_strlen(path);
	len_ext = ft_strlen(ext);
	if (len_path <= len_ext)
		return (0);
	return (ft_strncmp(path + len_path - len_ext, ext, len_ext) == 0);
}

char	*sl_strip_newline(char *line)
{
	size_t	len;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && (line[len - 1] == '\r' || line[len - 1] == '\n'))
		len--;
    if (len > 0 && (line[len - 1] == '\r' || line[len - 1] == '\n'))
		len--;
	return (ft_substr(line, 0, len));
}

char	**sl_grow_grid(char **grid, int old_cap, int new_cap)
{
	char	**new_grid;
	int		i;

	new_grid = ft_calloc(new_cap + 1, sizeof(char *));
	if (!new_grid)
		return (NULL);
	i = 0;
	while (i < old_cap)
	{
		new_grid[i] = grid[i];
		i++;
	}
	free(grid);
	return (new_grid);
}
