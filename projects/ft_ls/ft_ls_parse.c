/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 03:35:10 by jocarol           #+#    #+#             */
/*   Updated: 2017/05/22 06:23:20 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

static void			ft_usage()
{
	ft_putstr_fd("Usage : ./ft_ls [-alRrt] [file][1]\n", 2);
}

static void				ft_flag2struct(t_flag *flagStruct, char *flag)
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

static void				*ft_parseArgs(int ac, char **av, t_flag flag)
{
	int				sizeOfArg;
	t_flag		*flagStruct;

	i = 0;
	if (!(flagStruct = ft_memalloc(sizeof(*flagStruct))))
		return (NULL);
	while (++i < ac)
	{
		if (av[i][0] != '-')
			return (flagStruct);
		j = 0;
		sizeOfArg = ft_strlen(av[i]);
		while (++j < sizeOfArg)
			if (ft_flag2struct(flag, av, i, j))
				return (NULL);
	}
  printf("Flag -a :%d\n",flag->all);
 	printf("Flag -l :%d\n",flag->list);
 	printf("Flag -R :%d\n",flag->rec);
 	printf("Flag -r :%d\n",flag->rev);
 	printf("Flag -t :%d\n",flag->time);

	return (flagStruct);
}
