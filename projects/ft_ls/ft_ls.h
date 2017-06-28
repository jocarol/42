/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 03:35:10 by jocarol           #+#    #+#             */
/*   Updated: 2017/06/28 07:50:08 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "libft/libft.h"
#include "dirent.h"
#include <sys/stat.h>
#include <sys/types.h>

#define bool char
#define TRUE 1
#define FALSE 0

typedef struct		s_flag
{
	bool			all;
	bool			list;
	bool			rec;
	bool			rev;
	bool			time;
}					t_flag;

typedef struct		s_item
{
	bool			isFile;
	bool			isDir;
	int				type;
	char			inode;
	char			*name;
	const char		*path;
	struct s_item	*nxt;
	struct stat		st_stat;
//	ino_t			st_ino;    /* inode's number */
//	mode_t			st_mode;   /* inode protection mode */
//	nlink_t			st_nlink;  /* number of hard links to the file */
//	uid_t			st_uid;    /* user-id of owner */
//	gid_t			st_gid;    /* group-id of owner */
//	dev_t			st_rdev;   /* device type, for special file inode */
//	struct timespec	st_atimespec;  /* time of last access */
//	struct timespec	st_mtimespec;  /* time of last data modification */
//	struct timespec	st_ctimespec;  /* time of last file status change */
//	off_t			st_size;   /* file size, in bytes */
//	quad_t			st_blocks; /* blocks allocated for file */
//	u_long			st_blksize;/* optimal file sys I/O ops blocksize */
//	u_long			st_flags;  /* user defined flags for file */
//	u_long			st_gen;    /* file generation number */
}					t_item;

void				ft_parse(int ac, char **av, t_flag *flag, t_item *item);

#endif
