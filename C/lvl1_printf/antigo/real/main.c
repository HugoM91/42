
#include<stdio.h>

typedef struct ordem {

	char*	flag;
	int		min_width;
	int 	precision;
	int		max_width;
	char*	type;
	char*	to_print;
}	ordem;

int	main(void)
{
	ordem um;
	um.flag = "ola";

	printf("%s", um.flag);
}