# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 17:55:04 by gmorais-          #+#    #+#              #
#    Updated: 2023/07/12 16:33:56 by gmorais-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS_NAME =	main.c\
			utils.c

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

RM = rm -rf

LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft

OBJS = $(SRCS_NAME:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT)  -o $(NAME)

$(LIBFT):  $(shell make -C $(LIBFT_PATH) -q)
	make  -s -C $(LIBFT_PATH)
	make bonus  -s -C $(LIBFT_PATH)
		
clean:
		make clean -s -C $(LIBFT_PATH)
		rm -rf $(OBJS)

fclean: clean
		make fclean -s -C $(LIBFT_PATH)
		rm -f $(NAME)

re: fclean all

-rw-r--r-- 1 gmorais- 2022_lisboa 1779 Jul  5 12:39 main.c