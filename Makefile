# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 12:35:42 by tstripeb          #+#    #+#              #
#    Updated: 2020/02/18 15:03:15 by tstripeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRCS = srcs/checker.c srcs/stack.c srcs/message.c srcs/valid.c srcs/stack_utils.c srcs/commands_for_checker.c srcs/commands_spr.c

FLAGS = -Wall -Werror -Wextra -I./includes

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
			make -C libft
					gcc -o $(NAME) $(FLAGS) $(OBJ) libft/libft.a
							@echo "Checker done"

clean:
			make clean -C libft
					rm -f $(OBJ)

fclean: clean
			make fclean -C libft
					rm -f $(NAME)

re: fclean all
