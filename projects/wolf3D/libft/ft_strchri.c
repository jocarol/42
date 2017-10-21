#include "libft.h"

int		ft_strchri(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (*str == c)
			return (i);
		i++;
	}
	return (-1);
}
