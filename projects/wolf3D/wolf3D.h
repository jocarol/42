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
  double              pos_x;
  double              pos_y;
  double              dir_x;
  double              dir_y;
  double              plane_x;
  double              plane_y;
  double              camera_x;
  double              ray_pos_x;
  double              ray_pos_y;
  double              ray_dir_x;
  double              ray_dir_y;
  double              side_dist_x;
  double              side_dist_y;
  double              delta_dist_x;
  double              delta_dist_y;
  double              perp_wall_dist;
  int                 draw_start;
  int                 draw_end;
  int                 x;
  int                 step_x;
  int                 step_y;
  int                 map_x;
  int                 map_y;
  int                 line_height;
  int                 hit;
  int                 side;
}                     t_env;

#endif
