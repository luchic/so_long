#include "internal.h"

char	**init_array(int height, int widht)
{
	char	**res;
	int		i;

	res = (char **)ft_calloc(height, sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (i < height)
	{
		res[i] = ft_calloc(widht, sizeof(char *));
		i++;
	}
	return (res);
}

char	**copy_array(char **src, int height, int widht)
{
	int		i;
	int		j;
	char	**res;

	if (!src)
		return (NULL);
	res = init_array(height, widht);
	if (!res)
		return (NULL);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j <widht)
		{
			res[i][j] = src[i][j];
			j++;
		}
		i++;
	}
	return (res);
}
