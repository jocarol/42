/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 02:58:56 by jocarol           #+#    #+#             */
/*   Updated: 2017/03/22 02:58:58 by jocarol          ###   ########.fr       */
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
