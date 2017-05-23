#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_flag	*flag;


	if (!(flagStruct = ft_memalloc(sizeof(*flagStruct))))
		return (NULL);

	ft_parseArgs(ac, av);
	return (0);
}
