#include "../includes/fdf.h"

static int      x_count(int x, char *line)
{
  while (*line)
  {
    while (*line == ' ' || *line == '\t')
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

static char		*join_line(char *read_buff, char *line)
{
  char		    *tmp_read_buff;
  char		    *tmp_line;
  char		    *new_buff;
  size_t	    len;

  tmp_read_buff = read_buff;
  tmp_line = line;
  len = ft_strlen(line);
  while (--len && (line[len] == ' ' || line[len] == '\t'))
    line[len] = 0;
  new_buff = ft_strnjoin(3, (read_buff ? read_buff : ""), line, "\n");
  if (tmp_read_buff)
    free(tmp_read_buff);
  free(tmp_line);
  return (new_buff);
}

char          *map_check(const char *map_path, int *x, int *y)
{
  int         fd;
  int         coor_toll;
  int         state;
  char        *line;
  char        *read_buff;

  state = 1;
  line = NULL;
  read_buff = NULL;
  if (((fd = open(map_path, O_RDONLY)) || 1) && fd == -1)
    error(0, map_path);
  while ((state = ft_get_next_line(fd, &line)) && state == 1)
  {
    coor_toll = x_count(0,line);
    if (!*y)
      *x = coor_toll;
    else if (coor_toll == -1 || coor_toll != *x)
      return (NULL);
    read_buff = join_line(read_buff, line);
    (*y)++;
  }
  if (state < 0)
    error(0, 0);
  close(fd);
  return(read_buff);
}
