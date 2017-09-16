#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "mlx.h"
# include <errno.h>
# include <math.h>

# define WIN_NAME "Fractol"
//# define FRAC_NB	1
# define IMG_SIZE 800

typedef struct 					s_env
{
	void 									*mlx_ptr;
	void 									*win;
	void 									*img;
	char 									*data;
	char 									*frac_type;
	int										linesize;
	int										bpp;
	int										endian;
	int										iteration;
	int										x;
	int										y;
	double								zoomx;
	double								zoomy;
	double								c_r;
	double								c_i;
	double								x1;
	double								x2;
	double								y1;
	double								y2;
	double								r;
	double								i;
}												t_env;

#endif