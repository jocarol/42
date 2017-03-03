/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 11:46:04 by agrau             #+#    #+#             */
/*   Updated: 2017/02/11 07:41:33 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_usage(void)
{
	ft_putstr("fillit: usage: ./fillit valid_file\n");
}

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

int		main(int ac, char *av[])
{
	if (ac == 2)
		ft_solve(av[1]);
	else
		ft_usage();
	return (0);
}
