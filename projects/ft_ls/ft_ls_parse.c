/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 03:35:10 by jocarol           #+#    #+#             */
/*   Updated: 2017/06/03 09:32:46 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

static void				ft_usage()
{
	ft_putstr_fd("Usage : ./ft_ls [-alRrt] [file][1]\n", 2);
}

static void 			ft_setFlag(t_flag *flag)
{
	ft_bzero(flag, sizeof(t_flag));
}


static void					ft_setArg(t_item *item)
{
	item->isFile = FALSE;
	item->isDir = FALSE;
	item->type = 0;
	item->inode = 0;
	item->name = NULL;
	item->path = NULL;
}

static void				ft_flag2struct(t_flag *flagStruct, char *flag)
{
	int i = 0;
	while (flag[i])
	{
		if (flag[i] == 'a')
			flagStruct->all = TRUE;
		else if (flag[i] == 'l')
			flagStruct->list = TRUE;
		else if (flag[i] == 'R')
			flagStruct->rec = TRUE;
		else if (flag[i] == 'r')
			flagStruct->rev = TRUE;
		else if (flag[i] == 't')
			flagStruct->time = TRUE;
		else
		{
			free(flag);
			ft_usage();
		}
		i++;
	}
}

static	void 			ft_path2struct(t_item *item, char *av)
{
	if (item == NULL)
			item = malloc(sizeof(t_item));
	else
	{
			while (item->nxt)
			{
				item = item->nxt;
			}
			item->nxt = malloc(sizeof(t_item));
			item = item->nxt;
	}
	item->path = av;
	item->nxt = NULL;
}

static void				ft_parseArgs(int ac, char **av, t_flag *flag, t_item *item)
{
	int i;
	int stopFlag;

	i = 0;
	stopFlag = FALSE;
	while (++i < ac)
	{
		if (*av[i] != '-' || (*av[i] == '-' && *(*av + 1) == NULL))
		{
			stopFlag = TRUE;
			ft_path2struct(item, av[i]);
		}
		else if (*av[i] == "-" && av[i][1] == "-")
			stopFlag = TRUE;
		else if (*av[i] == "-" && stopFlag == FALSE)
			ft_flag2struct(flag, av[i]);
		else if (stopFlag == TRUE)
			ft_path2struct(item, av[i]);
		else
			ft_usage();
	}
}
