LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS =  ft_printf.c \
			includes/ft_char_string_per.c \
			includes/ft_flags.c	\
			includes/ft_hexa.c	\
			includes/ft_int.c	\
			includes/ft_itoa2.c	\
			includes/ft_misc2.c	\
			includes/ft_misc.c  \
			includes/ft_pointer.c \
			includes/ft_start.c  \
			includes/ft_uint.c \

		
SURPL_O = 	ft_char_string_per.o \
			ft_flags.o  \
			ft_hexa.o \
			ft_int.o  \
			ft_itoa2.o \
		    ft_misc2.o  \
			ft_misc.o  \
			ft_pointer.o \
			ft_start.o  \
			ft_uint.o \
			
CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O)
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all