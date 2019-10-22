# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmarks <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/06 10:59:03 by bmarks            #+#    #+#              #
#    Updated: 2019/07/25 10:16:39 by bmarks           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libps.a

NAME1 = checker

NAME2 = push_swap

SRC = operations.c \
	  c_operations.c \
	  stack_funcs.c \
	  c_stack_funcs.c \
	  warehouse.c \
	  core_logic.c \
	  comparitive.c \
	  comparitive2.c \
	  brute_solve.c \
	  big_solve.c \
	  small_solve.c \
	  error_snake.c

OBJ = $(SRC:%.c=%.o)

LIB = -L. -L libft/ -lps -lft

FLAGS = -Wall -Werror -Wextra

all:	$(NAME1) $(NAME2)

$(NAME): libft
	@gcc $(FLAGS) -c -I. $(SRC)
	@ar rc $(NAME) $(OBJ)

$(NAME1):	$(NAME)
	@gcc $(FLAGS) checker_main.c $(LIB) -o $(NAME1)
	@echo "Usage: ./checker [-c/-v] [arguments]"

$(NAME2):	$(NAME)
	@gcc $(FLAGS) push_swap_main.c $(LIB) -o $(NAME2)
	@echo "Usage: ./push_swap [arguments]"

clean:
	@/bin/rm -f $(OBJ)

fclean:	clean
	@/bin/rm -f $(NAME) $(NAME1) $(NAME2)

re:	fclean all

libft:
	@make -C libft/ fclean && make -C libft/

norm:
	@norminette -R CheckForbiddenSourceHeader
