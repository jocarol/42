#ifndef FT_LS_H
# define FT_LS_H

#include "libft/libft.h"
#include "dirent.h"

#define bool char
#define TRUE 1
#define FALSE 0

typedef struct			s_flag
{
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

t_flag					*ft_parseflags(int ac, char **av);
static int				ft_flag2struct(t_flag *flag, char **av, int i, int j);
static void				ft_usage();



#endif
