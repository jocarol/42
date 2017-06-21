/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 03:35:10 by jocarol           #+#    #+#             */
/*   Updated: 2017/06/21 17:06:30 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

void				display(char *item/*, t_flag flag*/)
{
		ft_putendl(item);
}

static void			ft_ls(char *path)
{
	DIR				*dirEntry;
	struct	dirent	*dirStream;

	if (!path)
		path = ".";
	dirEntry = opendir(path);
	if (dirEntry)
	{
		while ((dirStream = readdir(dirEntry)))
			display(dirStream->d_name);
		closedir(dirEntry);
	}
}

int					main(int ac, char **av)
{
	t_flag	flag;
	t_item	*item;

	item = ft_memalloc(sizeof(t_item));
	printf("\n-------------- <DEBUG PARTY> ---------------\n");
	printf("\n✓ Struct \'t_item\' malloced\n");
	printf("\n↪ Parsing...\n\n");
	ft_parse(ac, av, &flag, item);
	printf("✓ Parsing ok\n\n");
	printf("Flag detected :\n");
	printf("a : %d\n", flag.all);
	printf("l : %d\n", flag.list);
	printf("R : %d\n", flag.rec);
	printf("r : %d\n", flag.rev);
	printf("t : %d\n", flag.time);
	printf("\n\nListing directory : \n");
	ft_ls((char *)item->path);
	printf("\n\n-------------- </DEBUG PARTY> ---------------\n");
	return (0);
}
