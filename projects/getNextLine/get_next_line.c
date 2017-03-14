/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 05:10:19 by jocarol           #+#    #+#             */
/*   Updated: 2017/03/03 05:33:23 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_parse_data(char **data, char **line)
{
	char		*tmp;

	tmp = NULL;
	if (*data)
	{
		if ((tmp = ft_strchr((const char*)*data, '\n')))
		{
			*line = ft_strsub((char const*)*data, 0, tmp - *data);
			ft_memmove(*data, tmp + 1, ft_strlen(tmp));
		}
	}
}
