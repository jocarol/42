/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 03:35:10 by jocarol           #+#    #+#             */
/*   Updated: 2017/06/16 15:39:06 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

int		main(int ac, char **av)
{
	t_flag	flag;
	t_item	*item;

	item = ft_memalloc(sizeof(t_item));
	printf("\n-------------- <DEBUG PARTY> ---------------\n");
	printf("\n✓ Struct \'t_item\' malloced\n");
	printf("\n↪ Parsing...\n\n");
	ft_parse(ac, av, &flag, item);
	printf("✓ Parsing ok\n\n");
	display(item);
	printf("Flag detected :\n");
	printf("a : %d\n", flag.all);
	printf("l : %d\n", flag.list);
	printf("R : %d\n", flag.rec);
	printf("r : %d\n", flag.rev);
	printf("t : %d\n", flag.time);
	printf("\n-------------- </DEBUG PARTY> ---------------\n");
	return (0);
}
