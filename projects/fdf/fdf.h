#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <errno.h>
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include <time.h>

# define WIN_NAME "test"
# define WIN_W 800
# define WIN_H 800
# define IMG_W WIN_W + 200
# define IMG_H WIN_H + 200
# define DEFAULT_COLOR 0x00ff00
# define ALT ((*matrix)[n_y][n_x]).alt
# define COLOR ((*matrix)[n_y][n_x]).color
# define ZOOM ((t_computed*)(mlx->computed))->zoom
# define POS_X ((t_computed*)(mlx->computed))->pos_x
# define POS_Y ((t_computed*)(mlx->computed))->pos_y
# define ANGLE_X ((t_computed*)(mlx->computed))->alpha_x
# define ANGLE_Y ((t_computed*)(mlx->computed))->alpha_y
# define X1 (n_x + ALT * ANGLE_X / 42) * ZOOM
# define Y1 (n_y + ALT * ANGLE_Y / 42) * ZOOM
# define X2 X1 - Y1
# define YISO (X1 + Y1) / 2

typedef	struct		s_attr
{
	int							alt;
	int							color;
}									t_attr;

typedef struct		s_computed
{
	double					pos_x;
	double					pos_y;
	double					alpha_x;
	double					alpha_y;
	double					zoom;
}									t_computed;

typedef struct		s_env
{
	t_computed			*computed;
	void						*matrix;
	void						*mlx_ptr;
	void						*win;
	void						*img;
	char						*data;
	int							matrix_x;
	int							matrix_y;
	int							bpp;
	int							linesize;
	int							endian;
	int							projection;
}									t_env;

typedef struct		s_brez
{
	int							dx;
	int							dy;
	int							sx;
	int							sy;
	int							err;
	int							e2;
}									t_brez;

typedef struct		s_coor
{
	int							x;
	int							y;
}									t_coor;

char							*get_map_size(const char *file, int *y, int *x);
void							fdf_parser(const int y, const int x, t_attr matrix[y][x], \
															const char *read);
void							fdf_painter(const int y, const int x, t_attr matrix[y][x]);
long							errors(const int err, const char *name);
void							put_pixel(t_env *mlx, int x, int y, int color);
void							put_line(t_env *mlx, t_coor a, t_coor b, int color);
void							painter(t_env *mlx);
void							cleaner(t_env *mlx);
int								mouse(int button, int x, int y, void *param);
int								keys(int keycode, void *param);
void							zoom(t_env *mlx);
void							unzoom(t_env *mlx);
int								get_colorful(t_env *mlx, int n_x, int n_y);

#endif
