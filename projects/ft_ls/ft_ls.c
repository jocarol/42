/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 03:35:10 by jocarol           #+#    #+#             */
/*   Updated: 2017/06/16 11:52:34 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

int		main(int ac, char **av)
{
	t_flag	flag;
	t_item	*item;

	//ft_bzero(&item, sizeof(t_item));
	item = ft_memalloc(sizeof(t_item));
	printf("Struct \'item\' malloced\n");
	printf("\nParsing...\n");
	ft_parse(ac, av, &flag, item);
	display(item);
	printf("a : %d\n", flag.all);
	printf("l : %d\n", flag.list);
	printf("R : %d\n", flag.rec);
	printf("r : %d\n", flag.rev);
	printf("t : %d\n", flag.time);
	return (0);
}
