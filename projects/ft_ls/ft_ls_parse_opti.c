#include "ft_ls.h"
#include "stdio.h"


static void			ft_usage()
{
	ft_putstr_fd("Usage : ./ft_ls [-alRrt] [file][1]\n", 2);
}

 static t_flag		*ft_fail(t_flag *flag)
{
		free(flag);
		ft_usage();
		return (NULL);
}

t_flag				*ft_parseflags(int ac, char **av)
{
	char			**avPtr;
	t_flag			*flag;

	avPtr = av;
	if (!(flag = ft_memalloc(sizeof(*flag))))
		return (NULL);
	while ((++avPtr) - av < ac)
	{
		if (**avPtr != '-')
			return (NULL);
		if (*(*avPtr + 1) == 'a')
			flag->all = TRUE;
		else if (*(*avPtr + 1) == 'l')
			flag->list = TRUE;
		else if (*(*avPtr + 1) == 'R')
			flag->rec = TRUE;
		else if (*(*avPtr + 1) == 'r')
			flag->rev = TRUE;
		else if (*(*avPtr + 1) == 't')
			flag->time = TRUE;
		else
			return (ft_fail(flag));
	}
	printf("%d", flag->all);
	return (flag);
}

int					main(int ac, char **av)
{
	if(!(ft_parseflags(ac, av)))
		return (1);
	else
		return (0);
}
