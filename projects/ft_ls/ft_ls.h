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

typedef struct			s_item
{
	bool				isFile;
	bool				isDir;
	int					type;
	char				inode;
	char				*name;
	const char			*path;
	struct s_item		*nxt;

}						t_item;

static void				ft_parseArgs(int ac, char **av, t_flag *flag, t_item *item);
static void				ft_flag2struct(t_flag *flagStruct, char *flag);
static void 			ft_path2struct(t_item *item, char *av);
static void				ft_usage();


#endif
