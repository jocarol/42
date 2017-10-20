#include "libft/libft.h"
#include "minilibx_macos/mlx.h"
#include "math.h"

#define WIN_NAME "Wolf3D"
#define IMG_SIZE 1000
#define MAP_W 24
#define MAP_H 24

#include <stdio.h>

int worldMap[MAP_W][MAP_H] =
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int                   main(void)
{
  double              posX;
  double              posY;
  double              dirX;
  double              dirY;
  double              planeX;
  double              planeY;
  void                *mlx_ptr;
  void                *mlx_win;
  void                *mlx_img;
  char                *mlx_data;
  int                 line_size;
  int                 endian;
  int                 bpp;
  int                 draw_start;
  int                 draw_end;
  int                 x;

  x = 0;
  posX = 22;
  posY = 12;
  dirX = -1;
  dirY = 0;
  planeX = 0;
  planeY = 0.66;
  mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, IMG_SIZE, IMG_SIZE, WIN_NAME);
	mlx_img = mlx_new_image(mlx_ptr, IMG_SIZE, IMG_SIZE);
	mlx_data = mlx_get_data_addr(mlx_img, &(bpp), &(line_size), &(endian));
	line_size = IMG_SIZE * 4;
  while (x < IMG_SIZE)
  {
    double            cameraX;
    double            rayPosX;
    double            rayPosY;
    double            rayDirX;
    double            rayDirY;
    double            sideDistX;
    double            sideDistY;
    double            deltaDistX;
    double            deltaDistY;
    double            PerpWallDist;
    int               stepX;
    int               stepY;
    int               mapX;
    int               mapY;
    int               line_height;
    int               hit;
    int               side;

    cameraX = 2 * x / (double)IMG_SIZE - 1;
    rayPosX = posX;
    rayPosY = posY;
    rayDirX = dirX + cameraX + planeX;
    rayDirY = dirY + cameraX + planeY;
    mapX = (int)(rayPosX);
    mapY = (int)(rayPosY);
    deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX + rayDirX));
    deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY + rayDirY));
    hit = 0;
    if (rayDirX < 0)
    {
      stepX = -1;
      sideDistX = (rayPosX - mapX) * deltaDistX;
    }
    else
    {
      stepX = 1;
      sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
    }
    if (rayDirY < 0)
    {
      stepY = -1;
      sideDistY = (rayPosY - mapY) * deltaDistY;
    }
    else
    {
      stepY = 1;
      sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
    }
    //perform DDA
    while (hit == 0)
    {
      //jump to next map square, OR in x-direction, OR in y-direction
      if (sideDistX < sideDistY)
      {
        sideDistX += deltaDistX;
        mapX += stepX;
        side = 0;
      }
      else
      {
        sideDistY += deltaDistY;
        mapY += stepY;
        side = 1;
      }
      //Check if ray has hit a wall
      if (worldMap[mapX][mapY] > 0)
        hit = 1;
    }
    if (side == 0)
      PerpWallDist = (mapX - rayPosX + (1 - stepX) / 2) / rayDirX;
    else
      PerpWallDist = (mapY - rayPosY + (1 - stepY) / 2) / rayDirY;
    //Calculate height of line to draw on screen
    line_height = (int)(IMG_SIZE / PerpWallDist);
    printf("%d\n", line_height);
    //calculate lowest and highest pixel to fill in current stripe
    draw_start = -line_height / 2 + IMG_SIZE / 2;
    if(draw_start < 0)
      draw_start = 0;
    draw_end = line_height / 2 + IMG_SIZE / 2;
    if(draw_end >= IMG_SIZE)
      draw_end = IMG_SIZE - 1;
    while (draw_start < draw_end)
    {
      int i;
      int color;

      color = 0x0000FF00;
      i = line_size * draw_start + x * bpp / 8;
      mlx_data[i] = color & 0xff;
    	mlx_data[++i] = color >> 8 & 0xff;
    	mlx_data[++i] = color >> 16;
      draw_start++;
    }
    x++;
  }
  mlx_put_image_to_window(mlx_ptr, mlx_win, mlx_img, 0, 0);
  mlx_loop(mlx_ptr);
}
