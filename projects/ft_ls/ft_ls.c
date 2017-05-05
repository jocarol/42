/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 16:58:24 by jocarol           #+#    #+#             */
/*   Updated: 2017/04/25 17:03:16 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls(char *str)
{
	struct dirent		*dirStream;
	DIR					*dir;

	if ((dir = opendir(str)) == NULL)
		return (0);
	while ((dirStream = readdir(dir)))
	{
		ft_putstr(dirStream->d_name);
		ft_putstr("\n");
	}
	return (0);
}

int		main(int ac, char **av)
{
	ft_ls(av[1]);
	return (0);
}
