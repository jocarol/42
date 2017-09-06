#include <stdio.h>
#include "fdf.h"

void		zoom(t_env *env)
{
	ZOOM += 1;
}

void		unzoom(t_env *env)
{
	if (ZOOM > 1)
		ZOOM -= 1;
}

int			mouse(int button, int x, int y, void *param)
{
	cleaner(param);
	printf("%d ,%d\n",x,y );
	if (button == 4)
		zoom(param);
	else if (button == 5)
		unzoom(param);
	painter(param);
	return (0);
}
