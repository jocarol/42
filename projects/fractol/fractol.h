#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "mlx.h"
# include <errno.h>
# include <math.h>

# define WIN_NAME "Fractol"
# define IMG_SIZE 1000

typedef struct 					s_env
{
	void 									*mlx_ptr;
	void 									*win;
	void 									*img;
	char 									*data;
	int										linesize;
	int										bpp;
	int										endian;
	int										max_iteration;
	double								zoom;
	double								x1;
	double								y1;
	double								y2;
	double								r;
	double								i;
}												t_env;

#endif
