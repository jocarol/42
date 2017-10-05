#include "fractol.h"
#include <stdio.h>

int           main(int ac, char **av)
{
  t_env       z;

	if (ac == 2)
	{
		set_env(&z, av[1]);
		draw(&z);
		mlx_hook(z.win, 2, 3, keys, &z);
    mlx_hook(z.win, 6, 0, morph, &z);
		mlx_loop(z.mlx_ptr);
	}
	else
		usage();
	return (0);
}
