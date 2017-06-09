/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 03:35:10 by jocarol           #+#    #+#             */
/*   Updated: 2017/06/09 11:35:40 by jocarol          ###   ########.fr       */
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
		{
			ft_usage();
		}
	}
	printf("Flag parsed\n");
}

static	void 		ft_path2struct(t_item *item, char *av)
{
	t_item			*begin;

	begin = item;
	if (!begin)// == NULL)
	{
		if (!(begin = ft_memalloc(sizeof(t_item))))
			return;
		begin->path = av;
		begin->nxt = NULL;
		printf("element allocated & initialised at %p\n", (void *)&begin);
		// printf("1st element allocated at %p\n", (void *)&begin);
	}
	else
	{
		write(1, "LALALA\n", 7);
		while (begin)
			begin = begin->nxt;
		if (!(begin = ft_memalloc(sizeof(t_item))))
			return;
		begin->path = av;
		begin->nxt = NULL;
		printf("element allocated & initialised at %p\n", (void *)&begin);
	}
  begin = item;
	printf("Arg parsed : %s\n", av);
}

void        display(t_item *item)
{
  printf("slt");
  while(item)
  {
    printf("[%s]\n", item->path);
    item = item->nxt;
  }
}

void				ft_parse(int ac, char **av, t_flag *flag, t_item *item)
{
	int i;
	int stopFlag;
	printf("i & stopFlag declared\n");
	
	i = 0;
	stopFlag = FALSE;
	printf("variables initialised\n");
	while (++i < ac)
	{
		printf("i = %d\n", i);
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
    display(item);
	  printf("Parsing ok\n");
  }
}
