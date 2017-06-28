/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 03:35:10 by jocarol           #+#    #+#             */
/*   Updated: 2017/06/28 14:30:41 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

static void			display(t_item *item/*, t_flag flag*/)
{
	//	flag.all = (TRUE) ? setAll(item);
	//ft_putnbr((int)item->st_ino);
	printf("%ju\n", (uintmax_t)item->st_stat.st_ino);
}

static void			ft_ls(const char *path, t_item *item/*, t_flag flag*/)
{
	DIR				*dir;
	struct	dirent	*dirStream;

	if (!path)
		path = ".";
	dir = opendir(path);
	if (dir)
	{
		while ((dirStream = readdir(dir)))
		{
			if (*dirStream->d_name)
				display(item/*, flag*/);
		}
		closedir(dir);
	}
}

int					main(int ac, char **av)
{
	t_flag	flag;
	t_item	*item;
	
	ft_bzero((void *)&flag, sizeof(size_t));
	item = ft_memalloc(sizeof(t_item));
	ft_putendl("\n-------------- <DEBUG PARTY> ---------------\n");
	ft_putendl("\n✓ Struct \'t_item\' malloced\n");
	ft_putendl("↪ Parsing...");
	ft_parse(ac, av, &flag, item);
	ft_putendl("✓ Parsing ok\n\n");
	ft_putendl("Flag detected :\n");
	printf("a : %d\n", flag.all);
	printf("l : %d\n", flag.list);
	printf("R : %d\n", flag.rec);
	printf("r : %d\n", flag.rev);
	printf("t : %d\n", flag.time);
	ft_putendl("\n\nListing directory :");
	ft_ls(item->path, item/*, flag*/);
	ft_putendl("\n-------------- </DEBUG PARTY> ---------------\n");
	return (0);
}
