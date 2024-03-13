# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albestae <albestae@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 21:31:46 by albestae          #+#    #+#              #
#    Updated: 2024/03/13 04:44:59 by albestae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -MMD -MP

NAME = push_swap

SRC = src/ft_split.c src/init.c src/push_swap.c src/parsing_tab.c \
	src/parsing_input.c src/op/push.c src/op/reverse_rotate.c src/op/rotate.c \
	src/op/swap.c src/op/utils_lst.c src/utils.c src/sort_three_five.c \
	src/is_sorted_indexor.c src/push_b_opti.c src/min_max.c src/push_a.c \
	src/target.c src/select_move.c

HEADER = -I include

OBJ = $(SRC:.c=.o)

D = $(SRC:.c=.d)

all: $(NAME)

%.o:%.c
		$(CC) $(CFLAGS) -o $@ -c $< $(HEADER)

$(NAME): $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(HEADER)

clean:
		rm -rf $(OBJ)
		rm -rf $(D)

fclean: clean
		rm -rf $(NAME)

re: fclean 
	make all

.PHONY: all clean fclean re

-include $(D)
