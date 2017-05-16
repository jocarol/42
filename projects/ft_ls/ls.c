#include <stdio.h>

int parsez(char *a, t_flag flag)
{
    int i;
    int tog;

    tog = 0;
    i = 0;
    while(a[i++])
    {
        a[i] == 'a'? printf("flag->all = TRUE") : (tog++);
        a[i] == 'l'? printf("flag->list = TRUE") : (tog++);
        a[i] == 'R'? printf("flag->rec = TRUE") : (tog++);
        a[i] == 'r'? printf("flag->rev = TRUE") : (tog++);
        a[i] == 't'? printf("flag->time = TRUE") : (tog++);
        if(tog == 5)
	    {
	    	printf("free(flag)");
            printf("ft_usage();");
	    	return (1);
	    }
	    tog = 0;
    }
	return (0);
}



int main(int argc, char *argv[]) {
	// your code goes here
	if(argv[1]){
	    argv[1][0]=='-' ? parsez(argv[1]) : printf("faire autre chose");
	}
	
	return 0;
}
