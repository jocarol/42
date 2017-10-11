#include "libft.h"
#include "math.h"

#define WIN_NAME Wolf3D
#define IMG_SIZE 1000
#define MAP_W 24
#define MAP_H 24

int worldMap[MAP_W][MAP_H]=
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

int                   main(int argc, char **av)
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
  int                 linesize;
  int                 endian;
  int                 bpp;
  int                 x;

  x =0;
  posX = 22;
  posY = 12;
  dirX = -1;
  dirY = 0;
  planeX = 0;
  planeY = 0.66;
  mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, IMG_SIZE, IMG_SIZE, WIN_NAME);
	mlx_img = mlx_new_image(mlx_ptr, IMG_SIZE, IMG_SIZE);
	mlx_data = mlx_get_data_addr(img, &(bpp), &(linesize), &(endian));
	linesize = IMG_SIZE * 4;
  while (x < IMG_SIZE)
  {
    double            cameraX;
    double            rayPosX;
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
    int               hit;
    int               side;

    mapX = (rayPosX);
    mapY = (rayPosY);
    deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX + rayDirX));
    deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY + rayDirY);
    cameraX = 2 * x / (double)IMG_SIZE - 1;
    rayPosX = posX;
    rayPosY = posY;
    rayDirX = dirX + cameraX + planeX;
    rayDirY = dirY + cameraY + planeY;
    if (rayDirX < 0)
    {
      stepX = -1;
      sideDistX = (rayPosX - mapX) * deltaDistX;
    }
    else
    {
      stepX = 1;
      sideDistY = (mapX + 1.0 - rayPosX) * deltaDistX;
    }
    if (rayDirY < 0;)
    {
      stepY = -1;
      sideDistY = (rayPosY - mapY) * deltaDistY;
    }
    else
    {
      stepY = 1;
      sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
    }
    x++;
  }
}
