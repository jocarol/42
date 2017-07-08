/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 03:35:10 by jocarol           #+#    #+#             */
/*   Updated: 2017/06/28 14:30:41 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

static void	      ft_putnbrendl(int i)
{
	if (i == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (i < 0)
		{
			ft_putchar('-');
			i = -i;
		}
		if (i >= 10)
			ft_putnbr(i / 10);
		ft_putchar(i % 10 + '0');
	}
  ft_putchar('\n');
}

static char      *get_entry_path(const char *path, struct dirent *st_dir)
{
  char *entry_path;

  entry_path = ft_strjoin(path, "/");
  return (ft_strjoin(entry_path, st_dir->d_name));
}

static void 			display(const char *path, struct dirent *st_dir/*, t_flag flag*/)
{
  struct stat     *st_stat;
  char            *entry_path;
  //flag.all = (TRUE) ? setAll(item);
  //ft_putnbr((int)item->st_ino);
  //ft_putstr(path);
  //ft_putchar('/');
  if (!(st_stat = ft_memalloc(sizeof(st_stat))))
    exit(0);
  entry_path = get_entry_path(path, st_dir);
  printf("%s ", entry_path);
  stat(entry_path, st_stat);
  //ft_putstr(entry_path);
  ft_putchar(' ');
  printf("%ju\n", (uintmax_t)st_stat->st_ino);
  //ft_putnbrendl(st_stat->st_ino);
}

static void	  		ft_ls(const char *path/*, t_item *item, t_flag flag*/)
{
  DIR			        *dir;
  struct	dirent	*st_dir;

  if (!path)
    path = ".";
  dir = opendir(path);
  if (dir)
  {
    ft_putstr(path);
    ft_putendl(":");
    while ((st_dir = readdir(dir)))
    {
      display(path, st_dir/*, flag*/);
    }
    closedir(dir);
  }
}

int					      main(int ac, char **av)
{
  t_flag	        flag;
  t_item	        *item;

  ft_bzero((void *)&flag, sizeof(size_t));
  item = ft_memalloc(sizeof(t_item));
  ft_putendl("\n-------------- <DEBUG PARTY> ---------------\n");
  ft_putendl("\n✓ Struct \'t_item\' malloced\n");
  ft_putendl("↪ Parsing...");
  parse(ac, av, &flag, item);
  ft_putendl("✓ Parsing ok\n\n");
  ft_putendl("Flag detected :\n");
  printf("a : %d\n", flag.all);
  printf("l : %d\n", flag.list);
  printf("R : %d\n", flag.rec);
  printf("r : %d\n", flag.rev);
  printf("t : %d\n", flag.time);
  ft_putendl("\n\nListing directory :");
  ft_ls(item->path/*, item, flag*/);
  ft_putendl("\n-------------- </DEBUG PARTY> ---------------\n");
  return (0);
}
