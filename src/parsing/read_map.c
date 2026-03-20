/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:00:00 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/16 12:00:00 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static int	sl_push_line(char ***grid, int *count, int *cap, char *line)
{
	char	*clean;

	clean = sl_strip_newline(line);
	free(line);
	if (!clean || clean[0] == '\0')
		return (free(clean), 0);
	if (*count >= *cap)
	{
		*grid = sl_grow_grid(*grid, *cap, *cap * 2);
		if (!*grid)
			return (free(clean), 0);
		*cap *= 2;
	}
	(*grid)[*count] = clean;
	(*count)++;
	return (1);
}

static int	sl_load_lines(int fd, char ***grid, int *count, int *cap)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (!sl_push_line(grid, count, cap, line))
			return (0);
		line = get_next_line(fd);
	}
	return (1);
}

int	sl_read_map(const char *path, t_map *map)
{
	int		fd;
	char	**grid;
	int		count;
	int		cap;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	cap = 8;
	count = 0;
	grid = ft_calloc(cap + 1, sizeof(char *));
	if (!grid)
		return (close(fd), 0);
	if (!sl_load_lines(fd, &grid, &count, &cap))
		return (close(fd), free_araay_rows(grid, count), 0);
	close(fd);
	if (count == 0)
		return (free_araay_rows(grid, count), 0);
	map->grid = grid;
	map->height = count;
	map->width = ft_strlen(grid[0]);
	return (1);
}
