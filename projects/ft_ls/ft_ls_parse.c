/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 03:35:10 by jocarol           #+#    #+#             */
/*   Updated: 2017/05/26 23:44:18 by jocarol          ###   ########.fr       */
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
	flag->all = FALSE;
	flag->list = FALSE;
	flag->rec = FALSE;
	flag->rev = FALSE;
	flag->time = FALSE;
	// Pourquoi pas memeset ou un truc du genre??
}

//ft_bzero(arg, sizeof(t_arg));

static void					ft_setArg(t_arg *arg)
{
	arg->isFile = FALSE;
	arg->isDir = FALSE;
	arg->type = 0;
	arg->inode = 0;
	arg->name = NULL;
	arg->path = NULL;
}										t_item;

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
 je regarde mes argv,
 si c un fichier > go liste fichier sinon si c un dossier > go liste dossier else erreur ce fichier existe pas tu passe a l'aurre
*/
}

static void				ft_parseArgs(int ac, char **av, t_flag *flag, t_item *item)
{
	int i;
	int stopFlag;

	i = 0;
	stopFlag = FALSE;
	while (++i < ac)
	{
		if (*av[i] != "-" || (*av[i] == "-" && *(*av + 1) == NULL))
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
