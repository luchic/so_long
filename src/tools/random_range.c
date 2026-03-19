/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_range.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:24:18 by nluchini          #+#    #+#             */
/*   Updated: 2026/03/19 10:36:59 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include <sys/time.h>

// int	sl_random_range(int min, int max)
// {
// 	struct timeval	tv;
// 	static long		state;
// 	long			range;
// 	int				tmp;

// 	if (min > max)
// 	{
// 		tmp = min;
// 		min = max;
// 		max = tmp;
// 	}
// 	if (min == max)
// 		return (min);
// 	if (gettimeofday(&tv, NULL) == 0)
// 		state ^= (tv.tv_sec << 20) ^ tv.tv_usec;
// 	if (state == 0)
// 		state = 1;
// 	state = (state * 1103515245 + 12345) & 0x7fffffff;
// 	range = (long)max - (long)min + 1;
// 	return (min + (state % range));
// }

int	sl_random_range(int min, int max)
{
	static long		state;
	long			range;
	int				tmp;

	if (min > max)
	{
		tmp = min;
		min = max;
		max = tmp;
	}
	if (min == max)
		return (min);
	state = rand();
	range = (long)max - (long)min + 1;
	return (min + (state % range));
}
