#ifndef FT_LS_H
# define FT_LS_H

#include "libft/libft.h"

#define bool int
#define TRUE 1
#define FALSE 0

typedef struct			s_flag
{
	bool				check;
	bool				all;
	bool				list;
	bool				rec;
	bool				rev;
	bool				time;
}						t_flag;

typedef struct			s_element
{
	bool				isFile;
	bool				isDir;
	int					type;
	char				*path;
	char				*inode;
	char				*Name;
}						t_element;

static void				ft_usage();
t_flag					*ft_parseflags(int ac, char **av);

#endif
