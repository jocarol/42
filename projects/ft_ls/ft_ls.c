#include "ft_ls.h"
#include "stdio.h"

int		main(int ac, char **av)
{
	t_flag	*flag;
	t_item	*item;
	t_item	*begin;

	ft_parse(ac, av, flag, item);
	printf("a : %c\n", flag->all);
	printf("l : %c\n", flag->list);
	printf("R : %c\n", flag->rec);
	printf("r : %c\n", flag->rev);
	printf("t : %c\n", flag->time);
	while (item)
	{
		printf("%s\n", item->path);
		item = item->nxt;
	}
	return (0);
}
