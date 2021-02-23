
typedef struct ordem {

	char*	flag;
	int		min_width;
	int 	precision;
	int		max_width;
	char*	type;
}	ordem;

int	main(void)
{
	ordem um;
	um.flag = "ola";

	printf("%s", um.flag);
}