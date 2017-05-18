#include "ft_ls.h"

int		error(char c)
{
	char *str;

	str = "l,R,a,r,t,A,d,g,G,i,n,S,v,s,1,-";
	if (!ft_strchr(str, c))
	{
		ft_putstr("ft_ls: illegal option -- '");
		ft_putchar(c);
		ft_putstr("'\n");
		ft_putstr("usage: ls [-lRartAdgGinSvs1-] ");
		ft_putstr("[file ...]\n");
		return (1);
	}
	return (0);
}
