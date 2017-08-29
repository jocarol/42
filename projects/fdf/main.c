/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 13:41:29 by jocarol           #+#    #+#             */
/*   Updated: 2017/08/21 17:14:29 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void     fdf(const int x, const int y, const char *read_buff)
{
  t_attr  matrix[x][y];

  init_matrix(x, y, matrix);
  fill_matrix(matrix, read_buff, x, y);
  ft_memdel((void **)&read_buff);
  print_matrix(x, y, matrix[x][y]);
}

int             main(int argc, char *argv[])
{
  int           x;
  int           y;
  char          *read_buff;

  x = 0;
  y = 0;
  if (argc != 1)
  {
    if (!(read_buff = map_check(argv[1], &x, &y)))
      errors(3, argv[1]);
    else
      fdf(x, y, read_buff);
  }
  else
    errors(1, 0);
  return (0);
}
