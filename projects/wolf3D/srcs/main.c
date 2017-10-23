#include "Wolf3D.h"
#include <stdio.h>

t_point **get_map()
{
  t_point **ret;

  int tmp[24][24] =
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
  ret = (t_point**)malloc(sizeof(t_point*)*24);
  for(int i=0; i < 24; i++)
    ret[i] = (t_point*)malloc(sizeof(t_point)*24);
  for(int i=0; i<24; i++){
    for(int j=0; j<24;j++){
      ret[i][j].x=j;
      ret[i][j].y=i;
      ret[i][j].value = tmp[i][j];
      printf("x= %d y= %d z= %d\n", ret[i][j].x, ret[i][j].y, ret[i][j].value);
    }
  }
  return(ret);
}

void                  ignition(t_mlx *mlx, t_env *env)
{
  env->x = 0;
  env->pos_x = 22;
  env->pos_y = 12;
  env->dir_x = -1;
  env->dir_y = 0;
  env->plane_x = 0;
  env->plane_y = 0.66;
  mlx->mlx_ptr = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, IMG_SIZE, IMG_SIZE, WIN_NAME);
	mlx->mlx_img = mlx_new_image(mlx->mlx_ptr, IMG_SIZE, IMG_SIZE);
	mlx->mlx_data = mlx_get_data_addr(mlx->mlx_img, &(mlx->bpp), &(mlx->line_size), &(mlx->endian));
}

void                  init_env(t_env *env)
{
  env->camera_x = 2 * env->x / (double)IMG_SIZE - 1;
  env->ray_pos_x = env->pos_x;
  env->ray_pos_y = env->pos_y;
  env->ray_dir_x = env->dir_x + env->camera_x * env->plane_x;
  env->ray_dir_y = env->dir_y + env->camera_x * env->plane_y;
  env->map_x = (int)(env->ray_pos_x);
  env->map_y = (int)(env->ray_pos_y);
  env->delta_dist_x = sqrt(1 + (env->ray_dir_y * env->ray_dir_y) / (env->ray_dir_x * env->ray_dir_x));
  env->delta_dist_y = sqrt(1 + (env->ray_dir_x * env->ray_dir_x) / (env->ray_dir_y * env->ray_dir_y));
  env->hit = 0;
}

void                  init_dda(t_env *env)
{
  if (env->ray_dir_x < 0)
  {
    env->step_x = -1;
    env->side_dist_x = (env->ray_pos_x - env->map_x) * env->delta_dist_x;
  }
  else
  {
    env->step_x = 1;
    env->side_dist_x = (env->map_x + 1.0 - env->ray_pos_x) * env->delta_dist_x;
  }
  if (env->ray_dir_y < 0)
  {
    env->step_y = -1;
    env->side_dist_y = (env->ray_pos_y - env->map_y) * env->delta_dist_y;
  }
  else
  {
    env->step_y = 1;
    env->side_dist_y = (env->map_y + 1.0 - env->ray_pos_y) * env->delta_dist_y;
  }
}

void                  dda(t_env *env)
{
  while (!env->hit)
  {
    //jump to next map square, OR in x-direction, OR in y-direction
    if (env->side_dist_x < env->side_dist_y)
    {
      env->side_dist_x += env->delta_dist_x;
      env->map_x += env->step_x;
      env->side = 0;
    }
    else
    {
      env->side_dist_y += env->delta_dist_y;
      env->map_y += env->step_y;
      env->side = 1;
    }
    //Check if ray has hit a wall
    if (world_map[env->map_x][env->map_y] > 0)
      env->hit = 1;
  }
}

void                  get_perpdist(t_env *env)
{
  if (!env->side)
    env->perp_wall_dist = (env->map_x - env->ray_pos_x + (1 - env->step_x) / 2) / env->ray_dir_x;
  else
    env->perp_wall_dist = (env->map_y - env->ray_pos_y + (1 - env->step_y) / 2) / env->ray_dir_y;
}

void                  set_color(t_env env, int world_map)
{
  if (world_map == 1)
    env.color = NICE_PURPLE;
  else if (world_map == 2)
    env.color = NICE_BLUE;
  else if (world_map == 3)
    env.color = NICE_RED;
  else if (world_map == 4)
    env.color = NICE_GREEN;
  else if (world_map == 5)
    env.color = NICE_YELLOW;
  if (env.side)
    env.color = env.color / 2;
}

void                  put_vline(t_env env, t_mlx mlx, int world_map)
{
  set_color(env, world_map);
  while (env.draw_start < env.draw_end)
  {
    int i;

    i = mlx.line_size * env.draw_start + env.x * mlx.bpp / 8;
    mlx.mlx_data[i] = env.color & 0xff;
    mlx.mlx_data[++i] = env.color >> 8 & 0xff;
    mlx.mlx_data[++i] = env.color >> 16;
    env.draw_start++;
  }
}

void                  draw_wall(t_env env, t_mlx mlx, int world_map)
{
  // env.color = set_color(env, world_map[env.map_x][env.map_y])
  //Calculate height of line to draw on screen
  env.line_height = (int)(IMG_SIZE / env.perp_wall_dist);
  //calculate lowest and highest pixel to fill in current stripe
  env.draw_start = -env.line_height / 2 + IMG_SIZE / 2;
  if(env.draw_start < 0)
    env.draw_start = 0;
  env.draw_end = env.line_height / 2 + IMG_SIZE / 2;
  if(env.draw_end >= IMG_SIZE)
    env.draw_end = IMG_SIZE - 1;
  // set_color(env);
  put_vline(env, mlx, world_map);
}

void                  raycasting(t_mlx *mlx, t_env *env, int world_map)
{
  while (env->x < IMG_SIZE)
  {
    init_env(env);
    init_dda(env);
    dda(env);
    get_perpdist(env);
    draw_wall(*env, *mlx, world_map[env->map_x][env->map_y]);
    env->x++;
  }
}

void                  wolf3d(int world_map)
{
  t_mlx               mlx;
  t_env               env;

  ignition(&mlx, &env);
  raycasting(&mlx, &env, world_map);
  mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.mlx_img, 0, 0);
  mlx_loop(mlx.mlx_ptr);
}

int                   main(void)
{
  wolf3d(world_map);
  return(0);
}
