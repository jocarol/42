/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 02:58:28 by jocarol           #+#    #+#             */
/*   Updated: 2017/03/22 02:58:30 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct		s_tetri
{
	int				pos;
	int				f_left;
	int				f_up;
	char			*raw;
	int				**coor;
	struct s_tetri	*next;
}					t_tetri;

typedef struct		s_map
{
	t_tetri			*tetri;
	int				n;
	int				size;
	int				**map;
}					t_map;

int					**ft_map_alloc(int n);
int					**ft_coor_alloc();
int					**ft_raw_to_coor(const char *raw, int f_up, int f_left);
int					ft_first_up(const char *raw);
int					ft_first_left(const char *raw);
void				ft_list_create(t_tetri **tetri, char *path);
t_tetri				*ft_tetri_create(char *raw, int pos);
char				*ft_read_tetri_file(int fd);
void				ft_debug_slide_list(t_tetri **ltetri, void(*f)(t_tetri*));
void				ft_debug_print_raw(t_tetri *tetri);
void				ft_debug_print_coor(t_tetri *tetri);
void				ft_debug_print_raw_coor(t_tetri *tetri);
void				ft_debug_print_map(int **map, int n);
void				ft_free_all(t_tetri *ltetri, t_map *map);
void				ft_solve(char *path);
void				ft_tetri_pushback(t_tetri **ltetri, t_tetri *new);
int					ft_count_map_size(t_map *map);
int					ft_count_size(t_tetri *tetri);
int					ft_try_put_tetri(t_map *map, t_tetri *tetri, int k, int l);
int					**ft_put_tetri(t_map *map, t_tetri *tetri, int k, int l);
int					ft_backtracking(t_map *map, t_tetri *tetri);
char				*ft_coor_to_result(int **map, int size);
void				ft_usage();
void				ft_error();
int					ft_verif_tetri(char *raw);

#endif
