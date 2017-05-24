#ifndef FT_LS_H
# define FT_LS_H

#include "libft/libft.h"
#include "dirent.h"

#define bool char
#define TRUE 1
#define FALSE 0

typedef struct			s_flag
{
	bool							all;
	bool							list;
	bool							rec;
	bool							rev;
	bool							time;
}										t_flag;

typedef struct			s_item
{
	bool							isFile;
	bool							isDir;
	int								type;
	char							*inode;
	char							*name;
	char							*path;
}										t_item;

t_flag						*ft_parseArgs(int ac, char **av, t_flag flag);
static int				ft_flag2struct(t_flag *flagStruct, char *flag);
static void				ft_usage();



#endif
