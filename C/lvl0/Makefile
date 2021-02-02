SRCS			=		ft_isprint.c  ft_strchr.c   \
						ft_atoi.c     ft_itoa.c     ft_strdup.c   ft_strrchr.c   \
						ft_strjoin.c  ft_strstrim.c  \
						ft_calloc.c   ft_memchr.c   ft_strlcat.c  ft_substr.c    \
						ft_isalnum.c  ft_memcmp.c   ft_strlcpy.c  ft_tolower.c	\
						ft_isalpha.c  ft_strlen.c   ft_toupper.c	\
						ft_isascii.c  \
					    ft_strncmp.c	


OBJS			= $(SRCS:.c=.o)


CC				= gcc
RM				= rm -f

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)


.PHONY:			all clean fclean re
