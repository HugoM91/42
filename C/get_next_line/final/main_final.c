#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int		main(void)
{
    int		fd;
    char *file;
    char    buffer[2000 + 1];

    file = "ola.txt";
    fd = open(file, O_RDONLY);

	printf("Valor do F e de  - %d", fd);

    int r;
    int r2;
    r = read(fd, buffer, 2000);

    printf("\nValor do R e de - %d", r);

    while(r2 != r)
    {
        printf("%c", buffer[r2]);
        r2++;
    }
    printf("\n\n\n\n ---------------\n");
    printf("%s", buffer);
	return (0);
}