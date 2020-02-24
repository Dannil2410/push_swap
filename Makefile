# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 12:35:42 by tstripeb          #+#    #+#              #
#    Updated: 2020/02/24 15:30:05 by tstripeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = checker

NAME_P = push_swap

SRCS_C = srcs/checker.c srcs/stack.c srcs/message.c srcs/valid.c srcs/stack_utils.c srcs/commands_for_checker.c srcs/commands_spr.c

SRCS_P = srcs/push_swap.c srcs/commands_for_pushswap.c srcs/stack.c srcs/message.c srcs/valid.c srcs/commands_spr.c srcs/stack_utils.c srcs/commands_for_checker.c


FLAGS = -Wall -Werror -Wextra -I./includes

OBJ_C = $(SRCS_C:.c=.o)

OBJ_P = $(SRCS_P:.c=.o)

all:	$(NAME_C) $(NAME_P)

$(NAME_C): $(OBJ_C)
			make -C libft
					gcc -o $(NAME_C) $(FLAGS) $(OBJ_C) libft/libft.a
							@echo "Checker done"
$(NAME_P): $(OBJ_P)
			make re -C libft
					gcc -o $(NAME_P) $(FLAGS) $(OBJ_P) libft/libft.a
							@echo "Push_swap done"


clean:
			make clean -C libft
					rm -f $(OBJ_C)
					rm -f $(OBJ_P)

fclean: clean
			make fclean -C libft
					rm -f $(NAME_C)
					rm -f $(NAME_P)

re: fclean all
