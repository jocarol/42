#include "ft_ls.h"
#include "stdio.h"


static void			ft_usage()
{
	ft_putstr_fd("Usage : ./ft_ls [-alRrt] [file][1]\n", 2);
}
   
t_flag				*ft_parse_flags(char **av)
{
	int				i;
	size_t			j;
	t_flag			*flag;

	i = 0;
	j = 0;
	if (!(flag = (t_flag *)malloc(sizeof(*flag))))
	{
		ft_putstr_fd("E : Malloc failed.", 2);
		return (NULL);
	}
	else
	{
		ft_putstr_fd("Malloc OK. \n", 2);
		while (av[++i][0] == '-')
		{
			printf("i = %d \n", i);
			while (++j < ft_strlen(av[i]))
			{
				flag->all = (av[i][j] == 'a') ? TRUE : FALSE;
				flag->list = (av[i][j] == 'l') ? TRUE : FALSE;
				flag->rec = (av[i][j] == 'r') ? TRUE : FALSE;
				flag->rev = (av[i][j] == 'R') ? TRUE : FALSE;
				flag->time = (av[i][j] == 't') ? TRUE : FALSE;
				printf("av[i][j] = %c : i = %d\n", av[i][j], (int)j);
			}
		j = 0;
		ft_putstr_fd("j Reinitialized \n", 2);
		}
	}
	printf("all = %d \n", flag->all);
	printf("list = %d \n", flag->list);
	printf("rec = %d \n", flag->rec);
	printf("rev = %d \n", flag->rev);
	printf("time = %d \n", flag->time);
	return (flag);
}

static int			ft_checkflag(int ac, char **av)
{
	int				check;
	int				i;
	size_t			j;

	i = 0;
	check = 1;
	while (++i < ac)
	{
		j = 0;
		if (av[i][0] == '-')
		{
			while (++j < ft_strlen(av[i]) && check)
			{
				check = (av[i][j] == 'a' || av[i][j] == 'l' || av[i][j] == 'R'||
						av[i][j] == 'r' || av[i][j] == 't') ? 1 : 0;
				if (!check)
					ft_usage();
			}
		}
	}
	return (check);
}

int					main(int ac, char **av)
{
	if (!ft_checkflag(ac, av))
		return (1);
	ft_parse_flags(av);
	return (0);
}
