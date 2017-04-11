#ifndef FT_LS_H
# define FT_LS_H

#include "libft/libft.h"

#define bool int
#define TRUE 1
#define FALSE  0

typedef struct		s_flag
{
	bool			list;
	bool			recursive;
	bool			all;
	bool			reverseSort;
	bool			timeSort;
}					t_flag;

typedef struct		s_element
{
	bool			isFile;
	bool			isDir;
	int				type;
	char			*path;
	char			*inode;
	char			*Name;
}					t_element;

t_flag				*ft_parse_args(int ac, char **av);

#endif
