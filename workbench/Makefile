# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 17:43:16 by nmaturan          #+#    #+#              #
#    Updated: 2023/11/13 19:21:03 by nmaturan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Pro
NAME = push_swap

# Flags al compilar
FLAGS = -g -Wall -Wextra -Werror 
TESTFLAGS = -fsanitize=address -g

# DIRs
SRC_DIR = srcs/
INC_DIR = include/
LIBFT_DIR = libft/

# 
SRC_FILE = maintest.c 
INC_FILE = push_swap.h stack.h

# Compiling elements
SRC	= $(addprefix $(SRC_DIR), $(SRC_FILE))
INC = $(addprefix $(INC_DIR), $(INC_FILE))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

#### COMPILATION ####

all: $(LIBFT) $(NAME) 

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(INC) $(LIBFT)
	@echo Creating program $(NAME)...
	gcc $(FLAGS) $(SRC) -I$(INC_DIR) -L$(LIBFT_DIR) -lft -o $@

test: re all
	@echo "running script.sh"
	bash ./script.sh

fclean: clean
	@rm -f $(NAME) 
	@rm -f $(LIBFT)
	@rm -f $(TEST_OUT)

clean:
	@make clean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re test
