/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 05:10:19 by jocarol           #+#    #+#             */
/*   Updated: 2017/03/21 07:14:27 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

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
			return (1);
		}
	}
	return (0);
}

static	int		ft_fd_to_data(int fd, char **data, char **line)
{
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;

	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buffer[ret] = '\0';
		tmp = *data;
		if (*data)
		{
			*data = ft_strjoin(tmp, buffer);
			free(tmp);
		}
		else
			*data = ft_strdup((const char*)buffer);
		if (ft_parse_data(data, line))
			return (1);
	}
	return (0);
}

int					get_next_line(int const fd, char **line)
{
	int				res;
	static char		*ret[FD_VALUE];

	if (fd < 0 || !line)
		return (-1);
	if (ret[fd] && ft_parse_data(&ret[fd], line))
		return (1);
	res = ft_fd_to_data(fd, &ret[fd], line);
	if (res != 0)
		return (res);
	if (ret[fd] == NULL || ret[fd][0] == '\0')
		return (0);
	*line = ret[fd];
	ret[fd] = NULL;
	return (1);
}

/*int main(int ac, char **av)
{
	char *line;
	int fd1;
	fd1 = open(av[1], O_RDONLY);
	while (get_next_line(fd1, &line))
	{
		ft_putendl(line);
		free(line);
	}
	return(0);
}*/
