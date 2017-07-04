/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 03:35:10 by jocarol           #+#    #+#             */
/*   Updated: 2017/06/28 14:26:56 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

/*static void			getStats(const char *path, t_item *item)
{
	stat(path, item->st_stat);
}*/

void			display(const char *path, t_item *item/*, t_flag flag*/)
{
	if (path)
		if (item)
			;
	//	flag.all = (TRUE) ? setAll(item);
}

static void			usage()
{
	ft_putstr_fd("Usage : ./ft_ls [-alRrt] [file][1]\n", 2);
	exit(0);
}

static void			flag2struct(t_flag *flag, char *flagStr)
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
			usage();
	}
	printf("✓ Flag parsed : [%s]\n\n",flagStr);
}

static	void 		path2struct(t_item *item, char *av)
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

void				parse(int ac, char **av, t_flag *flag, t_item *item)
{
	int i;
	int stop_flag;

	i = 0;
	stop_flag = FALSE;
	while (++i < ac)
	{
		printf(". Current Av :	av[%d]\n", i);
		if (*av[i] != '-' || (*av[i] == '-' && ft_strlen(av[i]) == 1))
		{
			stop_flag = TRUE;
			path2struct(item, av[i]);
		}
		else if (*av[i] == '-' && av[i][1] == '-')
			stop_flag = TRUE;
		else if (*av[i] == '-' && stop_flag == FALSE)
			flag2struct(flag, av[i]);
		else if (stop_flag == TRUE)
			path2struct(item, av[i]);
		else
			usage();
	}
}
