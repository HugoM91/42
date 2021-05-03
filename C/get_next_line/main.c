#include <fcntl.h>
#include <stdio.h>
int				ft_strlen(const char *s)
{
	int			i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char				*ft_strdup(const char *s1)
{
	char			*s2;
	int			l;
	unsigned int	i;

	l = ft_strlen(s1);
	s2 = (char *)malloc(l + 1);
	i = 0;
	if (s2)
	{
		while (s1[i] != '\0' && i < l)
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
	}
	else
		return (0);
	return (s2);
}


char				*ft_substr(char const *s, unsigned int start, int len)
{
	char			*subst;
	int			maxl;
	int			i;
	int			j;

	if (!s)
		return (NULL);
	maxl = ft_strlen(s);
	if (start >= maxl)
		return (ft_strdup(""));
	if (!(subst = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = start;
	j = 0;
	while (j < len && s[i] != '\0')
	{
		subst[j] = s[i];
		j++;
		i++;
	}
	subst[j] = '\0';
	return (subst);
}


char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (!s2 || !s1)
		return (ft_strdup(""));
	if (!(str = (char *)malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}



char				*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (c == *s)
			return ((char *)s);
		s++;
	}
	if (c == '\0' && *s == '\0')
		return ((char *)s);
	return (NULL);
}

char				*ft_clean_line(char *save, char **line, int r)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			break ;
		i++;
	}
	if (i < ft_strlen(save))
	{
		*line = ft_substr(save, 0, i);
		tmp = ft_substr(save, i + 1, ft_strlen(save));
		free(save);
		save = ft_strdup(tmp);
		free(tmp);
	}
	else if (r == 0)
	{
		*line = save;
		save = NULL;
	}
	return (save);
}

char				*ft_save(char *buffer, char *save)
{
	char			*tmp;

	if (save)
	{
		tmp = ft_strjoin(save, buffer);
		free(save);
		save = ft_strdup(tmp);
		free(tmp);
	}
	else
		save = ft_strdup(buffer);
	return (save);
}

int					get_next_line(int fd, char **line)
{
	static char		*save[4096];
	char			buffer[BUFFER_SIZE + 1];
	int				r;

	while ((r = read(fd, buffer, BUFFER_SIZE)))
	{
		if (r == -1)
			return (-1);
		buffer[r] = '\0';
		save[fd] = ft_save(buffer, save[fd]);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (r <= 0 && !save[fd])
	{
		*line = ft_strdup("");
		return (r);
	}
	save[fd] = ft_clean_line(save[fd], line, r);
	if (r <= 0 && !save[fd])
		return (r);
	return (1);
}

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
	ft_test("test.txt");
	printf("\nTEST 2\n");
	ft_test("alphabet");
	printf("\nTEST 3\n");
	ft_test("empty_lines");
	printf("\nTEST 4\n");
	ft_test("empty_file");
	printf("\nTEST 5\n");
	ft_marge();
	printf("\nTEST 6\n");
	ft_test("4_newlines");
	printf("\n\n");

	//ft_test_huge("bible.txt");
	return (0);
}