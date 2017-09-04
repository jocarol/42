#include "fdf.h"

void					fill_matrix(const int y, const int x, t_attr matrix[y][x], \
											const char *read)
{
	int					n_y;
	int					n_x;

	n_y = -1;
	while (++n_y < y && (n_x = -1))
	{
		while (++n_x < x)
		{
			while (*read != '\n' && (*read == ' ' || *read == '\t'))
				read++;
			matrix[n_y][n_x].alt = ft_atoi(read);
			while (*read != '\n' && (ft_isdigit(*read) || *read == '-'))
				read++;
			if (*read == ',')
			{
				read++;
				matrix[n_y][n_x].color = ft_atoi_base(read, 16);
				while (*read != '\n' && ft_strchr("xABCDEF1234567890", *read))
					read++;
			}
			read++;
		}
	}
}

static int		get_values(char *line, int x)
{
	while (*line)
	{
		while (*line && (*line == ' ' || *line == '\t'))
			line++;
		if (*line && *line == '-')
			line++;
		if (*line)
		{
			if (ft_isdigit(*line))
				x++;
			else
				return (-1);
		}
		while (*line && ft_isdigit(*line))
			line++;
		if (*line == ',')
		{
			line++;
			while (*line && (ft_isdigit(*line) || ft_strchr("xABCDEF", *line)))
				line++;
		}
	}
	return (x);
}

static char		*join(char *read, char *line)
{
	char		*tmp_read;
	char		*tmp_line;
	char		*new;
	size_t	len;

	tmp_read = read;
	tmp_line = line;
	len = ft_strlen(line);
	while (--len && (line[len] == ' ' || line[len] == '\t'))
		line[len] = 0;
	new = ft_strnjoin(3, (read ? read : ""), line, "\n");
	if (tmp_read)
		free(tmp_read);
	free(tmp_line);
	return (new);
}

char					*get_map_size(const char *file, int *y, int *x		)
{
	char	*line;
	char	*read;
	int		fd;
	int		status;
	int		n_x;

	read = NULL;
	status = 1;
	if (((fd = open(file, O_RDONLY)) || 1) && fd == -1)
		errors(0, file);
	line = NULL;
	while ((status = get_next_line(fd, &line)) && status == 1)
	{
		n_x = get_values(line, 0);
		if (!*y)
			*x = n_x;
		else if (*x != n_x || n_x == -1)
			return (NULL);
		read = join(read, line);
		(*y)++;
	}
	if (status == -1)
		errors(0, 0);
	close(fd);
	return (read);
}
