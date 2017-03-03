/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fillit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 00:41:49 by agrau             #+#    #+#             */
/*   Updated: 2017/02/11 07:43:36 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_coor_to_result(int **coor, int size)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (!(str = (char *)ft_memalloc(sizeof(char) * ((size * size) + 1))))
		return (NULL);
	while (coor[i])
	{
		j = 0;
		while (coor[i][j] != -1)
		{
			if (coor[i][j] == 0)
				str[i * (size + 1) + j] = '.';
			else
				str[i * (size + 1) + j] = coor[i][j] + 'A' - 1;
			j++;
		}
		str[i * (size + 1) + j] = '\n';
		i++;
	}
	return (str);
}
