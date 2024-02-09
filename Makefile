# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albestae <albestae@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 21:31:46 by albestae          #+#    #+#              #
#    Updated: 2024/02/07 21:46:27 by albestae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

SRC = src/ft_split.c src/init.c src/push_swap.c src/parsing_tab.c \
	src/parsing_input.c src/op/push.c src/op/reverse_rotate.c src/op/rotate.c \
	src/op/swap.c src/op/utils_lst.c src/utils.c src/sort_three.c

HEADER = -I include

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o:%.c
		$(CC) $(CFLAGS) -o $@ -c $< $(HEADER)

$(NAME): $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(HEADER)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
