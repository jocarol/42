#include "fractol.h"

void 					mandle_init(t_env *z)
{
	z->x1 = -2.1;
	z->x2 = 0.6;
	z->y1 = -1.2;
	z->y2 = 1.2;
	z->r = 0.0;
	z->i = 0.0;
	z->zoomx = IMG_SIZE / (z->x2 - z->x1);
	z->zoomy = IMG_SIZE / (z->y2 - z->y1);
	z->c_r = z->x / z->zoomx + z->x1;
	z->c_i = z->y / z->zoomy + z->y1;
	z->iteration = 200;
	z->linesize = IMG_SIZE * 4;
}

void 					julia_init(t_env *z)
{
	z->x1 = -1.0;
	z->x2 = 1;
	z->y1 = -1.2;
	z->y2 = 1.2;
	z->c_r = 0.285;
	z->c_i = 0.01;
	z->zoomx = IMG_SIZE / (z->x2 - z->x1);
	z->zoomy = IMG_SIZE / (z->y2 - z->y1);
	z->r = z->x / z->zoomx + z->x1;
	z->i = z->y / z->zoomy + z->y1;;
	z->iteration = 200;
	z->linesize = IMG_SIZE * 4;
}

void 					bs_init(t_env *z)
{
	z->x1 = -1.0;
	z->x2 = 1;
	z->y1 = -1.2;
	z->y2 = 1.2;
	z->zoomx = IMG_SIZE / (z->x2 - z->x1);
	z->zoomy = IMG_SIZE / (z->y2 - z->y1);
	z->c_r = z->x / z->zoomx + z->x1;
	z->c_i = z->x / z->zoomx + z->x1;
	z->r = 0;
	z->i = 0;
	z->iteration = 200;
	z->linesize = IMG_SIZE * 4;
}
