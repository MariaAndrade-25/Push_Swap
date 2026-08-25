NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

SRC = main.c push_swap.c split.c parse.c stack_init.c \
	op_swap.c op_push.c \
	op_rotate.c op_reverse.c \
	sort_small.c sort_radix.c sort_chunk.c \
	utils.c utils_chunk.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re