/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 03:35:10 by jocarol           #+#    #+#             */
/*   Updated: 2017/06/21 15:13:54 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

static void			ft_usage()
{
	ft_putstr_fd("Usage : ./ft_ls [-alRrt] [file][1]\n", 2);
	exit(0);
}

static void			ft_flag2struct(t_flag *flag, char *flagStr)
{
	int i;

	i = 0;
	while (flagStr[++i])
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
			ft_usage();
	}
	printf("✓ Flag parsed : [%s]\n\n",flagStr);
}

static	void 		ft_path2struct(t_item *item, char *av)
{
	t_item			*tmp;

	tmp = item;
	if (!(tmp->path))
	{
		printf("↪ Empty linked list. Creating first link...\n");
		printf("✓ First link allocated & initialised at [%p]\n", (void *)&tmp);
		tmp->path = ft_strdup(av);
		tmp->nxt = NULL;
	}
	else
	{
		printf("↪ Adding link to existing path struct...\n");
		while (tmp->nxt)
			tmp = tmp->nxt;
		if (!(tmp->nxt = ft_memalloc(sizeof(t_item))))
			exit(0);
		tmp->nxt->path = ft_strdup(av);
		tmp->nxt->nxt = NULL;
		printf("✓ Link allocated & initialised at [%p]\n", (void *)&tmp->nxt);
	}
	printf("✓ Path parsed :	[%s]\n\n", av);
}

void				ft_parse(int ac, char **av, t_flag *flag, t_item *item)
{
	int i;
	int stopFlag;

	i = 0
	stopFlag = FALSE;
	while (++i < ac)
	{
		printf(". Current Av :	av[%d]\n", i);
		if (*av[i] != '-' || (*av[i] == '-' && ft_strlen(av[i]) == 1))
		{
			stopFlag = TRUE;
			ft_path2struct(item, av[i]);
		}
		else if (*av[i] == '-' && av[i][1] == '-')
			stopFlag = TRUE;
		else if (*av[i] == '-' && stopFlag == FALSE)
			ft_flag2struct(flag, av[i]);
		else if (stopFlag == TRUE)
			ft_path2struct(item, av[i]);
		else
			ft_usage();
	}
}
