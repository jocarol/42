/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:26:13 by jocarol           #+#    #+#             */
/*   Updated: 2017/10/26 09:47:04 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "mlx.h"
# include <errno.h>
# include <math.h>
# include <pthread.h>

# define WIN_NAME "jocarol@Fractol"
# define IMG_SIZE 800
# define MANDLEBROT 1
# define JULIA 2
# define BURNINGSHIP 3
# define N_THREADS 8
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define STR_ZOOM itoa_fractol(z->zoom)
# define STR_ITER itoa_fractol(z->iteration)
# define AD mlx_get_data_addr(z->img, &(z->bpp), &(z->linesize), &(z->endian));

typedef struct				s_env
{
	int						key;
	void					*mlx_ptr;
	void					*win;
	void					*img;
	char					*data;
	double					zoom;
	double					c_r;
	double					c_i;
	double					x1;
	double					x2;
	double					y1;
	double					y2;
	double					r;
	double					i;
	int						frac_type;
	int						iteration;
	int						linesize;
	int						endian;
	int						bpp;
	int						x;
	int						y;
	int						col;
	int						display_info;
	int						lock;
}							t_env;

typedef struct				s_mother_thread
{
	int						thread_id;
	t_env					*env_thread;
}							t_mother_thread;

void						usage(void);
void						mandle_init(t_env *z);
void						julia_init(t_env *z);
void						bs_init(t_env *z);
void						set_env(t_env *z, char *av);
void						draw(t_env *z);
int							keys(int keycode, t_env *z);
int							keys2(int keycode, t_env *z);
int							mouse(int key, int x, int y, t_env *z);
char						*itoa_fractol(uintmax_t n);
int							morph(int x, int y, t_env *z);
void						put_pixel(t_env *z, int x, int y, int color);

#endif
