/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 16:22:16 by jocarol           #+#    #+#             */
/*   Updated: 2017/08/21 17:14:59 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void            init_matrix(const int x, const int y, t_attr **matrix)
{
  int           n_x;
  int           n_y;

  n_y = -1;
  while (++n_y < y && (n_x = -1))
  {
      while (++n_x < x)
      {
        (matrix[n_x][n_y]).alt = 0;
        matrix[n_x][n_y].color = DEFAULT_COLOR;
      }
  }
}

void            fill_matrix(const char *read_buff, const int x, \
                const int y, t_attr **matrix)
{
  int           n_x;
  int           n_y;

  n_y = -1;
  while (++n_y < y && (n_x = -1))
  {
    while (++n_x < x)
    {
      while ((*read_buff == ' ' || *read_buff == '\t') && *read_buff != '\n')
        read_buff++;
      matrix[n_x][n_y].alt = ft_atoi(read_buff);
      while ((ft_isdigit(*read_buff) || *read_buff == '-') && \
            *read_buff != '\n')
        read_buff++;
      if (*read_buff == '-')
      {
        read_buff++;
        matrix[n_x][n_y].color = ft_atoi_base(read_buff, 16);
        while (ft_strchr("xABCDEF1234567890", *read_buff))
          read_buff++;
      }
      read_buff++;
    }
  }
}
