#include "ft_ls.h"
#include "stdio.h"


static void			ft_usage()
{
	ft_putstr_fd("Usage : ./ft_ls [-alRrt] [file][1]\n", 2);
}

static void			ft_fail(t_flag flag)
{
		free(flag);
		ft_usage();
		return (NULL);
}

t_flag				*ft_parseflags(int ac, char **av)
{
	int				i;
	size_t			j;
	int				sizeOfArg;
	t_flag			*flag;

	i = 0;
	j = 0;
	sizeOfArg = ft_strlen(av[i]);
	if (!(flag = ft_memalloc(sizeof(*flag))))
		return (NULL);
	while (++i < ac && av[i][0] == '-')
	{
		while (++j < ft_[i]))
		{
			if (av[i][j] == 'a')
				flag->all = TRUE;
			else if (av[i][j] == 'l')
				flag->list = TRUE;
			else if (av[i][j] == 'R')
				flag->rec = TRUE;
			else if (av[i][j] == 'r')
				flag->rev = TRUE;
			else if (av[i][j] == 't')
				flag->time = TRUE;
			else
				ft_fail(flag);
		}
		j = 0;
	}
	if (flag->check == FALSE)
		ft_fail(flag);
	return (flag);
}

int					main(int ac, char **av)
{
	if(!(ft_parseflags(ac, av)))
		return (1);
	else
		return (0);
}
