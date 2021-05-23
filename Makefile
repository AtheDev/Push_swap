NAME = push_swap

SRCS = srcs/main.c srcs/print.c srcs/swap.c srcs/push.c srcs/rotate.c \
	   srcs/reverse_rotate.c srcs/arg.c srcs/utils.c srcs/struct.c \
	   srcs/small_sort.c srcs/sort.c srcs/value.c srcs/process_push.c \
	   srcs/position.c srcs/chunck.c srcs/parsing.c srcs/parsing_utils.c

OBJS = $(SRCS:.c=.o)

INCLD = -I includes -I libft

CC = clang

RM = rm -f

CFLAGS = -Wall -Werror -Wextra -g

LDFLAGS = -L libft

all: $(NAME)

$(NAME): $(OBJS)
		make bonus -C libft
		$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME) -lft

$(OBJS): %.o: %.c
		$(CC) $(FLAGS) $(INCLD) -o $@ -c $<

clean:
		$(RM) $(OBJS)
		make clean -C libft

fclean: clean
		$(RM) $(NAME)
		$(RM) libft/$(NAME)

re: fclean all

.PHONY: all clean fclean re
