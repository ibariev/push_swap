NAME =		push_swap

SRCS = 		cmd_list.c		commands.c		main.c			markup.c\
			parser.c		prepare.c		process_a.c		process_b.c\
			sort_stack.c	stack.c			utils.c

OBJS =		$(SRCS:.c=.o)

RM =		rm -f

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror

HEADER =	push_swap.h

LIBFT_DIR =	libft

LIBFT =		libft/libft.a

all:		subsystem $(NAME)

%.o:		%.c $(HEADER) $(LIBFT)
			$(CC) $(CFLAGS) -c $< -o $@

subsystem:
			make -C $(LIBFT_DIR)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $^ $(LIBFT) -o $@

clean:		
			$(RM) $(OBJS)
			make clean -C $(LIBFT_DIR)

fclean:		clean
			$(RM) $(NAME)
			make fclean -C $(LIBFT_DIR)

re:			fclean all

.PHONY:		all clean fclean re