#ifndef WOLF3D_H
# define WOLF3D_H
# include "libft/libft.h"
# include "mlx.h"
# include <errno.h>
# include <math.h>
# include <fcntl.h>
# include <time.h>

#define WIN_NAME "jocarol's Wolf3D"
#define IMG_SIZE 1000
#define MAP_W 24
#define MAP_H 24

typedef struct        s_mlx
{
  void                *mlx_ptr;
  void                *mlx_win;
  void                *mlx_img;
  char                *mlx_data;
  int                 line_size;
  int                 endian;
  int                 bpp;
}                     t_mlx;

typedef struct        s_env
{
  double              posX;
  double              posY;
  double              dirX;
  double              dirY;
  double              planeX;
  double              planeY;
  double              cameraX;
  double              rayPosX;
  double              rayPosY;
  double              rayDirX;
  double              rayDirY;
  double              sideDistX;
  double              sideDistY;
  double              deltaDistX;
  double              deltaDistY;
  double              PerpWallDist;
  int                 draw_start;
  int                 draw_end;
  int                 x;
  int                 stepX;
  int                 stepY;
  int                 mapX;
  int                 mapY;
  int                 line_height;
  int                 hit;
  int                 side;
}                     t_env;

#endif
