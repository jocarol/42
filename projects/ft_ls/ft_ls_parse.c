#include "ft_ls.h"
#include "stdio.h"

static void			ft_usage()
{
	ft_putstr_fd("Usage : ./ft_ls [-alRrt] [file][1]\n", 2);
}

static int			ft_flag2struct(t_flag *flag, char **av, int i, int j)
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
	{
		free(flag);
		ft_usage();
		return (1);
	}
	return (0);
}

t_flag				*ft_parseflags(int ac, char **av)
{
	int				i;
	int				j;
	int				sizeOfArg;
	t_flag			*flag;

	i = 0;
	if (!(flag = ft_memalloc(sizeof(*flag))))
		return (NULL);
	while (++i < ac)
	{
		if (av[i][0] != '-')
			return (flag);
		j = 0;
		sizeOfArg = ft_strlen(av[i]);
		while (++j < sizeOfArg)
			if (ft_flag2struct(flag, av, i, j))
				return (NULL);
	}
	return (flag);
}

int					main(int ac, char **av)
{
	ft_parseflags(ac, av);
}
