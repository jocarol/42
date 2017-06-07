/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 03:35:10 by jocarol           #+#    #+#             */
/*   Updated: 2017/06/07 09:07:38 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

static void			ft_usage()
{
	ft_putstr_fd("Usage : ./ft_ls [-alRrt] [file][1]\n", 2);
}

//	ft_bzero(flag, sizeof(t_flag));

static void			ft_setStructs(t_flag *flag, t_item *item)
{
	if (!(flag = malloc(sizeof(*flag))))
		return;
	if (!(item = malloc(sizeof(*item))))
		return;
	else
	{
		ft_bzero((void*)flag, sizeof(*flag));
		ft_bzero((void*)item, sizeof(*item));
	}
}

static void			ft_flag2struct(t_flag *flag, char *flagStr)
{
	int i;

	i = 0;
	while (flagStr[i])
	{
		if (flagStr[i] == 'a')
			flag->all = TRUE;
		else if (flagStr[i] == 'l')
			flag->list = TRUE;
		else if (flagStr[i] == 'R')
			flag->rec = TRUE;
		else if (flagStr[i] == 'r')
			flag->rev = TRUE;
		else if (flagStr[i] == 't')
			flag->time = TRUE;
		else
		{
			free(flag);
			ft_usage();
		}
		i++;
	}
}

static	void 		ft_path2struct(t_item *item, char *av)
{
	if (item == NULL)
			item = malloc(sizeof(t_item));
	else
	{
		printf("Malloc ok");
		while (item->nxt)
		{
			item = item->nxt;
			item->nxt = malloc(sizeof(t_item));
			item = item->nxt;
		}
	}
	item->path = av;
	item->nxt = NULL;
}

void				ft_parse(int ac, char **av, t_flag *flag, t_item *item)
{
	int i;
	int stopFlag;

	i = 0;
	stopFlag = FALSE;
	ft_setStructs(flag, item);
	while (++i < ac)
	{
		if (*av[i] != '-' || (*av[i] == '-' && !*(*av + 1)))
		{
			stopFlag = TRUE;
//			ft_path2struct(item, av[i]);
		}
		else if (*av[i] == '-' && av[i][1] == '-')
			stopFlag = TRUE;
		else if (*av[i] == '-' && stopFlag == '-')
			ft_flag2struct(flag, av[i]);
//		else if (stopFlag == TRUE)
//			ft_path2struct(item, av[i]);
		else
			ft_usage();
	}
	printf("Parsing ok");
}
