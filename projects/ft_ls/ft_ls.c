#include "ft_ls.h"

t_flag			*ft_parse_flags(int ac, char **av)
{
	t_flag *flags;
	int i;
	int j;

	i = 1;
	j = 1;
	if	(!(flags = (t_flag *)malloc(sizeof(*flags))))
		return (NULL);
	else
	{
		while (av[i][0] == '-')
		{
			while (av[i][j])
			{
				switch (av[i][j])
				{
					case 'a' : flags->all = TRUE;
					case 'l' : flags->list = TRUE;
					case 'R' : flags->recursive = TRUE;
					case 'r' : flags->reverseSort = TRUE;
					case 't' : flags->timeSort = TRUE;
					default : ft_puterr("Usage : ./ft_ls [-alRrt] [file]");
				}
				j++;
			}
			i++;
		}
	}
	return (flags);
}
