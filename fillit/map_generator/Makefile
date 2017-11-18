NAME = map_gen
SRC = map_generator.c ../../libft/libft.a
FLAGS = -Wall -Wextra -Werror
CC = gcc

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)
clean:
	rm -f $(NAME)
fclean: clean
re: fclean all

.PHONY: all clean fclean re
