/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 20:15:48 by jocarol           #+#    #+#             */
/*   Updated: 2017/01/05 20:15:51 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 10

void	ft_putstr(char *c, int output)
{
	int i;

	i = 0;
	while (c[i])
	{
		write(output, &c[i], 1);
		i++;
	}
}

int		main(int argc, char *argv[])
{
	char	fd;
	int		i;
	char	buff[BUFF_SIZE + 1];

	if (argc == 1)
		ft_putstr("File name missing.\n", 2);
	if (argc > 2)
		ft_putstr("Too many arguments.\n", 2);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd)
		{
			while ((i = read(fd, buff, BUFF_SIZE)))
			{
				buff[i] = '\0';
				ft_putstr(buff, 1);
			}
			close(fd);
		}
	}
	return (0);
}
