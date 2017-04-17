#include "ft_ls.h"
#include "libft/libft.h"

void			ft_usage()
{
	ft_putstr_fd("Usage : ./ft_ls [-alRrt] [file][1]", 2);
}

t_flag			*ft_parse_flags(int ac, char **av)
{
	t_flag *flags;
	int i;
	int j;
	
	i = 0;
	if	(!(flags = (t_flag *)malloc(sizeof(*flags))))
		return (NULL);
	else
	{
		while (av[i++][0] == '-')
		{
			for (j = 1; j < ft_strlen(av[i]); j++)
			{
				if (av[i][j] == 'a')
					flags->all = TRUE;
				if (av[i][j] == 'l')
					flags->list = TRUE;
				if (av[i][j] == 'R')
					flags->recursive = TRUE;
				if (av[i][j] == 'r')
					flags->reverseSort= TRUE;
				if (av[i][j] == 't')
					flags->timeSort = TRUE;
				else
					ft_usage();
			}
		}
	}
	return (flags);
}

int	maint(int ac, char **av)
{
	ft_parse_flags(ac, av);
	return (0);
}
