#include "fdf.h"

long        errors(const int err, const char *name)
{
  ft_putstr_fd("fdf: ", 2);
  if (name)
  {
    ft_putstr_fd(name, 2);
    ft_putstr_fd(" ", 2);
  }
  if (err == 0)
    ft_putendl_fd(strerror(errno),2);
  else if (err == 1)
    ft_putstr_fd("\nUsage: fdf [file]\n", 2);
  else if (err == 2)
    ft_putstr_fd("\n", 2);
  else if (err == 3)
    ft_putstr_fd(" : Invalid map\n", 2);
  exit(1);
  return (0);
}
