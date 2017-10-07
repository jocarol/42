#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "mlx.h"
# include <errno.h>
# include <math.h>
# include <pthread.h>

# define WIN_NAME "Fractol"
# define IMG_SIZE 800
# define MANDLEBROT 1
# define JULIA 2
# define BURNINGSHIP 3
# define N_THREADS 8

typedef struct 					s_env
{
	void 									*mlx_ptr;
	void 									*win;
	void 									*img;
	char 									*data;
	double								zoom;
	double								c_r;
	double								c_i;
	double								x1;
	double								x2;
	double								y1;
	double								y2;
	double								r;
	double								i;
	int 									frac_type;
	int										iteration;
	int										linesize;
	int										endian;
	int										bpp;
	int										x;
	int										y;
	int										col;
	int										display_info;
	int										lock;
}												t_env;

typedef struct					mother_thread
{
	int										thread_id;
	t_env									*env_thread;
}												t_mother_thread;

void 										mandle_init(t_env *z);
void 										julia_init(t_env *z);
void 										bs_init(t_env *z);
void										set_env(t_env *z, char *av);
void										draw(t_env *z);
int											keys(int keycode, t_env *z);
int											morph(int x, int y, t_env *z);
void										usage();

#endif
