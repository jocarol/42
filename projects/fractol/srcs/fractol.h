#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "mlx.h"
# include <errno.h>
# include <math.h>

# define WIN_NAME "Fractol"
# define IMG_SIZE 800
# define MANDLEBROT 1
# define JULIA 2
# define BURNINGSHIP 3

typedef struct 					s_env
{
	void 									*mlx_ptr;
	void 									*win;
	void 									*img;
	char 									*data;
	int 									frac_type;
	int										col;
	int										linesize;
	int										bpp;
	int										endian;
	int										iteration;
	int										x;
	int										y;
	double								zoom;
	double								c_r;
	double								c_i;
	double								x1;
	double								x2;
	double								y1;
	double								y2;
	double								r;
	double								i;
	int										test;
}												t_env;

void 										mandle_init(t_env *z);
void 										julia_init(t_env *z);
void 										bs_init(t_env *z);

#endif
