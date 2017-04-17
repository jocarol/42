#ifndef FT_LS_H
# define FT_LS_H

#include "libft/libft.h"

#define bool int
#define TRUE 1
#define FALSE  0

typedef struct		s_flag
{
	bool			all : 1;
	bool			list: 1;
	bool			rec : 1;
	bool			rev :1;
	bool			time : 1;
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

static void			ft_usage();
static int			ft_checkflag(int c, char **av);
t_flag				*ft_parse_flags(char **av);

#endif
