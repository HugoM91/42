
#include<stdio.h>


int		get_next_line(int fd, char **line)
{
	/*char			*buff;
	static char		*save;
	int				reader;

	reader = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!has_return(save) && reader != 0)
	{
		if ((reader = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[reader] = '\0';
		save = join_str(save, buff);
	}
	free(buff);
	*line = get_line(save);
	save = get_save(save);
	if (reader == 0)
		return (0);
	return (1);*/
    return 0;
}


int main(int argc, char *argv[]){
/*
   if(argc == 2){
      printf("The argument supplied is %s\n", argv[1]);
   }
   else if(argc > 2){
      printf("Too many arguments supplied.\n");
   }
   else{
      printf("One argument expected.\n");
   }
*/

    char ch;
    FILE *fp;
    char **line;
    char *res;

    fp = fopen("ola.txt", "r"); // read mode

    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        return 0;
    }

    while((ch = fgetc(fp)) != EOF)
        printf("%c", ch);

    
    fclose(fp);

    get_next_line(fp, **line);

   return 0;

   
}