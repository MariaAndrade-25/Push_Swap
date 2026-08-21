NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c split.c parse.c stack.c \
	operations_swap.c operations_push.c \
	operations_rotate.c operations_reverse.c \
	sort.c sort_small.c sort_radix.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
