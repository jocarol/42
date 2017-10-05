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
	int										lock;
	int										display_info;
	// int										x_param;
	// int										y_param;
	double								zoom;
	double								c_r;
	double								c_i;
	double								x1;
	double								x2;
	double								y1;
	double								y2;
	double								r;
	double								i;
}												t_env;

void 										mandle_init(t_env *z);
void 										julia_init(t_env *z);
void 										bs_init(t_env *z);
void										set_env(t_env *z, char *av);
void										draw(t_env *z);
int											keys(int keycode, t_env *z);
int											morph(int x, int y, t_env *z);
// void 										display_info(t_env *z);
void										usage();

#endif
