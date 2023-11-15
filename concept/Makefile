
# PROGRAM
NAME = push_swap

# INCLUDE LIBFT
LIBFT = ./libft/
LFT = libft.a

# TEST
SRC = push_swap.c ft_utils.c
INC = push_swap.h stack.h

# FLAGS
FLAGS = -fsanitize=address -g -Wall -Wextra -Werror

all: libft $(NAME)

libft:
	make -C $(LIBFT)

$(NAME): $(SRC) $(INC) Makefile
	gcc $(FLAGS) $(SRC) -L$(LIBFT) -lft -o $@ 

clean:
	make -C $(LIBFT) clean 

fclean: clean
	rm $(NAME)
	rm $(LIBFT)$(LFT)

re: fclean all

.PHONY: all libft clean fclean re
