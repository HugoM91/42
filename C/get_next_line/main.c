#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
int	ft_test(char *file)
{
	int		fd;
	int		i;
	int		j;
	char    *line = 0;
	char	*lineadress[66];

	j = 1;
	if (!(fd = open(file, O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		lineadress[j - 1] = line;
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
	return (0);
}

int		main(void)
{
	printf("\nTEST 1\n");
	ft_test("ola.txt");
	return (0);
}