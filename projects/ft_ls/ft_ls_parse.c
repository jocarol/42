/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 03:35:10 by jocarol           #+#    #+#             */
/*   Updated: 2017/05/25 14:50:02 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

static void				ft_usage()
{
	ft_putstr_fd("Usage : ./ft_ls [-alRrt] [file][1]\n", 2);
}

static void 			ft_InitFlagStruct(t_flag *flag)
{
	flag->all = 0;
	flag->list = 0;
	flag->rec = 0;
	flag->rev = 0;
	flag->time = 0;
	// Pourquoi pas memeset ou un truc du genre??
}

static void				ft_flag2struct(t_flag *flagStruct, char *flag)
{
	while (++*flag)
	{
		if (*flag == 'a')
		flag->all = TRUE;
		else if (*flag == 'l')
		flag->list = TRUE;
		else if (*flag == 'R')
		flag->rec = TRUE;
		else if (*flag == 'r')
		flag->rev = TRUE;
		else if (*flag == 't')
		flag->time = TRUE;
		else
		{
			free(flag);
			ft_usage();
			return (1);
		}
	}
	return (0);
}

static	void 			ft_path2struct(t_item *item, char *av)
{
 /*
**

*/
}

static void				ft_parseArgs(int ac, char **av, t_flag *flag, t_item *item)
{
	int i;
	int stop;

	i = 0;
	stop = FALSE;
	while (++i < ac)
	{
		if (av[i][0] == "-" && stop == FALSE)
			ft_flag2struct(flag, av[i]);
		else if (av[i][0] != "-" || stop == TRUE)
		{
			ft_path2struct(item, av[i]);
			stop = TRUE;
		}
		else if (av[i][0] == '-' && av[i][1] == '-')
			stop = TRUE)
		else
			ft_usage();
	}
  printf("Flag -a :%d\n",flag->all);
 	printf("Flag -l :%d\n",flag->list);
 	printf("Flag -R :%d\n",flag->rec);
 	printf("Flag -r :%d\n",flag->rev);
 	printf("Flag -t :%d\n",flag->time);

	return (flagStruct);
}
